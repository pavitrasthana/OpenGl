//#include<glad/glad.h>
//#include<GLFW/glfw3.h>
//
//#include<iostream>
//
//#include<glm/glm.hpp>
//#include<glm/gtc/matrix_transform.hpp>
//#include<glm/gtc/type_ptr.hpp>
//
//
//const int SCR_WIDTH = 640;
//const int SCR_HEIGHT = 640;
//
//void frameBuffer_Size_Callback(GLFWwindow* window, int width, int height);
//unsigned int Compileshader();
//
////Shader Sources.................................
//const char* vertexShaderCode =
//"#version 330 core\n"
//"layout (location = 0) in vec3 vPos;\n"
//"layout (location = 1) in vec3 vCol;\n"
//"out vec3 outCol;\n"
//"void main()\n"
//"{\n"
//"    gl_Position= vec4(vPos.x,vPos.y,vPos.z,1.0f);\n"
//"	outCol=vec3(vPos.x,vPos.y,vPos.z);\n"
//"}\0";
//
//const char* fragmentShaderCode =
//"#version 330 core\n"
//"out vec4 FragColor;\n"
//"in vec3 outCol;\n"
//"uniform float timeT;\n" //Range[0,1] Sin(a) ->Used
//"void main()\n"
//"{\n"
//"    FragColor = vec4(outCol.xyz,1.0f);\n"
//"}\0";
////................................................
//
//
//typedef glm::vec2 vec2;
//
//void Triangle(vec2 points[], vec2 a, vec2 b, vec2 c)
//{
//	static int i = 0;
//	points[i++] = a;
//	points[i++] = b;
//	points[i++] = c;
//
//}
//
//void DivideTriagle(vec2 points[], vec2 a, vec2 b, vec2 c, int k)
//{
//	if (k > 0)
//	{
//		vec2 ab = (a + b) / 2.f;
//		vec2 cb = (c + b) / 2.f;
//		vec2 ac = (a + c) / 2.f;
//
//		DivideTriagle(points, a, ab, ac, k - 1);
//		DivideTriagle(points, b, ab, cb, k - 1);
//		DivideTriagle(points, c, cb, ac, k - 1);
//	}
//	else
//	{
//		Triangle(points,a,b,c);
//	}
//	
//}
//
//int main()
//{
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "OPENGL WINDOW", NULL, NULL);
//	if (window == NULL)
//	{
//		std::cout << "FAILED TO CREATE A WINDOW!" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		std::cout << "FAILED TO INITIALIZE GLAD!" << std::endl;
//		return -1;
//	}
//
//
//	//Get the vertices data from array. 36 bytes to render a single triangle
//	//X=radius*Cos(angle)
//	//Y=radius*Cos(angle)
//
//
//
//
//
//
//	glfwSetFramebufferSizeCallback(window, frameBuffer_Size_Callback);
//
//	const int NumberofDivisions = 6;
//	const int NumVertices = 2187;
//
//	vec2 points[NumVertices];
//	vec2 pointA = vec2(0.f, 1.f);
//	vec2 pointB = vec2(-1.f, -1.f);
//	vec2 pointC = vec2(1.f, -1.f);
//
//	DivideTriagle(points, pointA, pointB, pointC, NumberofDivisions);
//
//	//Get reference for the linked shader.
//	unsigned int shaderProgram = Compileshader();
//	//Create VBO,VAO
//	unsigned int VBO, VAO, EBO;
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//
//
//	glBindVertexArray(VAO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);
//
//	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//
//	glBindVertexArray(0);
//
//	//.........................................
//
//	while (!glfwWindowShouldClose(window))//hold the window
//	{
//		glClearColor(0.25f, 0.5f, 0.7f, 0.0f);//RGBA (A - ALPHA(OPACITY))
//		glClear(GL_COLOR_BUFFER_BIT);
//		glUseProgram(shaderProgram);
//		glBindVertexArray(VAO);
//		
//		glDrawArrays(GL_TRIANGLES, 0,NumVertices);
//		
//
//
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//	return 0;
//}
//
//void frameBuffer_Size_Callback(GLFWwindow* window, int width, int height)
//{
//	glViewport(0, 0, width, height);
//}
//
//unsigned int Compileshader()
//{
//	unsigned int shaderProgram;
//	unsigned int vertexShader, fragmentShader;
//	//Vertex Shader compilation
//	vertexShader = glCreateShader(GL_VERTEX_SHADER);
//	glShaderSource(vertexShader, 1, &vertexShaderCode, NULL);
//	glCompileShader(vertexShader);
//
//	int success;
//	char infoLog[512];
//
//	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//	if (!success)
//	{
//		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//		std::cout << "ERROR!Vertex Shader compilation failed!\n" << infoLog << std::endl;
//	}
//
//	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//	glShaderSource(fragmentShader, 1, &fragmentShaderCode, NULL);
//	glCompileShader(fragmentShader);
//
//	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
//	if (!success)
//	{
//		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
//		std::cout << "ERROR!Fragment Shader compilation failed!\n" << infoLog << std::endl;
//	}
//
//	shaderProgram = glCreateProgram();
//	glAttachShader(shaderProgram, vertexShader);
//	glAttachShader(shaderProgram, fragmentShader);
//	glLinkProgram(shaderProgram);
//
//	glGetShaderiv(shaderProgram, GL_COMPILE_STATUS, &success);
//	if (!success)
//	{
//		glGetShaderInfoLog(shaderProgram, 512, NULL, infoLog);
//		std::cout << "ERROR!Shader linking failed!\n" << infoLog << std::endl;
//	}
//	glDeleteShader(vertexShader);
//	glDeleteShader(fragmentShader);
//
//	return shaderProgram;
//}
//
