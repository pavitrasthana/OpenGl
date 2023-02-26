//#include<glad/glad.h>
//#include<GLFW/glfw3.h>
//
//#include<iostream>
//#include<cmath>
//
//const int SCR_WIDTH = 640;
//const int SCR_HEIGHT = 480;
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
//	//Get the vertices data from array. 36 bytes to render a single triangle
//	float vertices[] = {
//	   -0.75f,0.25f,0.0f,1.0f,0.0f,0.0f, //left   1 stride - 24 bytes including color  --1st vertex of pentagon
//		0.0f,1.0f,0.0f,0.0f,1.0f,0.0f, //right  2 strides - 12 bytes    2nd vertex of pentagon
//		0.75f,0.25f,0.0f,0.0f,0.0f,1.0f, //top    3 strides - 12 bytes   3rd vertex of pentagon
//
//		0.35f,-0.75f,0.0f,1.0f,0.0f,0.0f,  // 4th vertex of pentagon
//		-0.35f,-0.75f,0.0f,1.0f,0.0f,0.0f, //5th vertex of pentagon
//
//
//	};//96 bytes for square
//
//	unsigned int indices[] = {
//		0,1,4,
//		2,1,3,
//		3,1,4
//	};
//
//	glfwSetFramebufferSizeCallback(window, frameBuffer_Size_Callback);
//
//	//Get reference for the linked shader.
//	unsigned int shaderProgram = Compileshader();
//	//Create VBO,VAO
//	unsigned int VBO, VAO, EBO;
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//	glGenBuffers(1, &EBO);
//
//
//	glBindVertexArray(VAO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
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
//
//		glUseProgram(shaderProgram);
//		glBindVertexArray(VAO);
//		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
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