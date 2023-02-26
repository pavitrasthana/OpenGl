//#include<glad/glad.h>
//#include<GLFW/glfw3.h>
//#include<glm/glm.hpp>
//#include<glm/gtc/matrix_transform.hpp>
//#include<glm/gtc/type_ptr.hpp>
//
//#include<iostream>
//#include<cmath>
//#include<vector>
//
//float xMove, yMove;
//const int SCR_WIDTH = 800; // width and height in pixels
//const int SCR_HEIGHT = 800;
//
//float radius = 0.7f;
//int sectorCount = 72;
//int stackCount = 24;
//
//std::vector<float> vertices;
//std::vector<unsigned int> indices;
//
//void framebufferSizeCallback(GLFWwindow* window, int width, int height);
//unsigned int CompileShader();
//void processInput(GLFWwindow* window);
//void GenerateVertices();
//void AddVertex(float x, float y, float z);
//void AddIndices(unsigned int i1, unsigned int i2, unsigned int i3);
//
//
////Shader Sources......................................
//const char* vertexShaderCode =
//"#version 330 core\n"
//"layout (location = 0) in vec3 aPos;\n"
//"out vec3 aCol;\n"
//"uniform mat4 transform;\n"
//"void main()\n"
//"{\n"
//"   gl_Position = transform* vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//"   aCol = vec3(aPos.x, aPos.y, aPos.z);\n"
//"}\0";
//
////fragment shader contain color data for each and every pixel of window
//const char* fragmnetShaderCode =
//"#version 330 core\n"
//"out vec4 FragColor;\n"
//"in vec3 aCol;\n"
//"uniform float tTime;\n"
//"void main()\n"
//"{\n"
//"   FragColor = vec4(aCol.x*tTime,aCol.y*tTime,aCol.z*tTime, 1.0f);\n"
//"}\n\0";
////..................................................
//
//
//int main()
//{
//	glfwInit();                                    //Initialisation
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); /* as we are using Opengl v3.3 Major is for 3 and minor is for 3 (after decimal)*/
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //to set that we are using modern opengl version
//
//	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "OPENGL WINDOW", NULL, NULL);//address for o/p window object
//	if (window == NULL)     //To check if window is created or not
//	{
//		std::cout << "FAILED TO CREATE A WINDOW!" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window); // as there may be multiple window, so this function check to which window we are referring. here we are referring "window" Line 16.
//	glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
//
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) //initialize window object
//	{
//		std::cout << "FAILED TO INITIALIZE GLAD!" << std::endl;
//		return -1;
//	}
//
//	GenerateVertices();
//
//	//Get ref for the linked shader
//	unsigned int shaderProgram = CompileShader();
//
//	//Create Vertex Buffer Object(VBO) and Vertex Array Object(VAO).
//	unsigned int VBO, VAO, EBO;
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//	glGenBuffers(1, &EBO);
//
//	glBindVertexArray(VAO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);  // size of vertices array, as triangle is not a moving object we use GL_STATIC_DRAW. for moving objects we use GL_DYNAMIC_DRAW
//
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);
//
//	//we are defining following data in VAO
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);  //3 is for xyz values
//	glEnableVertexAttribArray(0);
//
//	glBindVertexArray(0);
//
//	//--------------------------------------------------------
//
//	while (!glfwWindowShouldClose(window)) //Run the code inside the while loop until we close the window
//	{
//		//processInput(window);
//
//		glClearColor(0.0f, 0.1f, 0.2f, 1.0f);//RGBA R- RED||G - GREEN || B- BLUE || A - ALPHA(OPACITY)
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//		glUseProgram(shaderProgram);
//		glEnable(GL_DEPTH_TEST);
//		float tTime = glfwGetTime();
//		glm::mat4 transform = glm::mat4(1.0f);
//		transform = glm::translate(transform, glm::vec3(xMove, yMove, 1.5f));
//		transform = glm::rotate(transform, tTime, glm::vec3(1.0f, 1.0f, 1.5f));
//		int attLoc = glGetUniformLocation(shaderProgram, "transform");
//		glUniformMatrix4fv(attLoc, 1, GL_FALSE, glm::value_ptr(transform));
//		attLoc = glGetUniformLocation(shaderProgram, "tTime");
//		glUniform1f(attLoc, cos(tTime));
//		glPointSize(6.0f);
//		glBindVertexArray(VAO);
//
//		//glDrawElements(GL_LINES, indices.size(), GL_UNSIGNED_INT, (void*)0);
//		//glDrawElements(GL_POINTS, indices.size(), GL_UNSIGNED_INT, (void*)0);
//		glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, (void*)0);
//
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//	return 0;
//}
//
//void framebufferSizeCallback(GLFWwindow* window, int width, int height)    //adjust and resize content inside the window
//{
//	glViewport(0, 0, width, height);   //set the view at center of screen as axis x = 0 and y = 0.
//}
//
//unsigned int CompileShader()
//{
//	unsigned int shaderProgram;    //define an unsigned variable
//	unsigned int vertexShader, fragmentShader; //define variables for vertex and fragment shader
//
//	//Vertex Shader Compilation
//	vertexShader = glCreateShader(GL_VERTEX_SHADER);
//	glShaderSource(vertexShader, 1, &vertexShaderCode, NULL); //Copying the vertex shader code into this function
//	glCompileShader(vertexShader);
//
//	/*Check the compilation success and print any error*/
//	int success;
//	char infoLog[512];
//	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);  //to check compilation status
//	if (!success)
//	{
//		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//		std::cout << "ERROR! Vertex Shader Compilation Failed!\n" << infoLog << std::endl;
//	}
//
//	//Fragment Shader Compilation
//	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//	glShaderSource(fragmentShader, 1, &fragmnetShaderCode, NULL); //Copying the vertex shader code into this function
//	glCompileShader(fragmentShader);
//
//	/*Check the compilation success and print any error*/
//	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);  //to check compilation status
//	if (!success)
//	{
//		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
//		std::cout << "ERROR! Fragment Shader Compilation Failed!\n" << infoLog << std::endl;
//	}
//
//	shaderProgram = glCreateProgram();
//	glAttachShader(shaderProgram, vertexShader);
//	glAttachShader(shaderProgram, fragmentShader);
//	glLinkProgram(shaderProgram);
//
//	glGetShaderiv(shaderProgram, GL_COMPILE_STATUS, &success);  //to check compilation status
//	if (!success)
//	{
//		glGetShaderInfoLog(shaderProgram, 512, NULL, infoLog);
//		std::cout << "ERROR! Shader Linking Failed!\n" << infoLog << std::endl;
//	}
//
//	//once linking happened delete vertex and fragment shader for optimization
//	glDeleteShader(vertexShader);
//	glDeleteShader(fragmentShader);
//
//	return shaderProgram;
//}
//
//void GenerateVertices()
//{
//	const float PI = acos(-1);     //3.1415....radian || 180 degrees
//
//	float x, y, z;
//
//	float sectorDivision = (2 * PI) / sectorCount;
//	float stackDivision = PI / stackCount;
//	float sectorAngle, stackAngle;
//
//	for (int i = 0; i <= stackCount; i++)
//	{
//		stackAngle = PI / 2 - i * stackDivision;
//		z = radius * sin(stackAngle);
//
//		for (int j = 0; j <= sectorCount; j++)
//		{
//			sectorAngle = j * sectorDivision;
//
//			float xy = radius * cos(stackAngle);
//
//			x = xy * cos(sectorAngle);
//			y = xy * sin(sectorAngle);
//
//			AddVertex(x, y, z);
//		}
//	}
//
//	unsigned int k1, k2;
//	for (int i = 0; i < stackCount; i++)
//	{
//		k1 = i * (sectorCount + 1);
//		k2 = k1 + sectorCount + 1;
//
//		for (int j = 0; j < sectorCount; ++j, ++k1, ++k2)
//		{
//			if (i != 0)
//				AddIndices(k1, k2, k1 + 1);
//
//			if (i != (stackCount - 1))
//			{
//				AddIndices(k1 + 1, k2, k2 + 1);
//			}
//		}
//	}
//}
//
//void AddVertex(float x, float y, float z)
//{
//	vertices.push_back(x);
//	vertices.push_back(y);
//	vertices.push_back(z);
//}
//
//void AddIndices(unsigned int i1, unsigned int i2, unsigned int i3)
//{
//	indices.push_back(i1);
//	indices.push_back(i2);
//	indices.push_back(i3);
//}