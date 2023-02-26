//#include<glad/glad.h>
//#include<GLFW/glfw3.h>
//
//#include<iostream>
//#include<cmath>
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
//"	outCol=vCol;\n"
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
//	float radius = 0.5f;
//	const int divisions = 50;
//	float PI = acos(-1);
//	float angle = 0;
//
//	float xValue, yValue;
//
//	//Get the vertices data from array. 36 bytes to render a single triangle
//	float vertices[divisions * 6];
//	//X=radius*Cos(angle)
//	//Y=radius*Cos(angle)
//
//
//	for (int i = 0; i < divisions; i++)
//	{
//		angle = (((PI * 2) / divisions)*i);
//		xValue = radius * (cos(angle));
//		yValue = radius * (sin(angle));
//		vertices[6*i] = xValue;
//		vertices[(6*i)+1] = yValue;
//		vertices[(6*i)+2] = 0.f;
//		vertices[(6 * i) + 3] = xValue;
//		vertices[(6 * i) + 4] = yValue;
//		vertices[(6 * i) + 5] = cos(yValue);
//
//	}
//
//	
//
//	glfwSetFramebufferSizeCallback(window, frameBuffer_Size_Callback);
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
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//
//	glBindVertexArray(0);
//
//	//.........................................
//
//	while (!glfwWindowShouldClose(window))//hold the window
//	{
//		glClearColor(1.0f, 0.5f, 0.7f, 0.0f);//RGBA (A - ALPHA(OPACITY))
//		glClear(GL_COLOR_BUFFER_BIT);
//		glLineWidth(2.f);
//		glUseProgram(shaderProgram);
//		glBindVertexArray(VAO);
//		/*int uniformLocTimeT = glGetUniformLocation(shaderProgram, "offset");
//		float value = glfwGetTime();
//		glUniform2f(uniformLocTimeT, cos(value), sin(value));*/
//		//glDrawArrays(GL_TRIANGLES, 0, 12);
//		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//		glDrawArrays(GL_TRIANGLE_FAN, 0, divisions);
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