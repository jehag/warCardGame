//#include <fstream>
//#include <iostream>
//#include <iomanip>
//#include <string>
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <conio.h>
//#include <GLFW/glfw3.h>
//#include "Engine.h"
//using namespace std;
//
//
//int main(void)
//{
//	GLFWwindow* window;
//
//	/* Initialize the library */
//	if (!glfwInit())
//		return -1;
//
//	/* Create a windowed mode window and its OpenGL context */
//	window = glfwCreateWindow(1920, 1080, "Hello World", NULL, NULL);
//	if (!window)
//	{
//		glfwTerminate();
//		return -1;
//	}
//
//	/* Make the window's context current */
//	glfwMakeContextCurrent(window);
//
//	/* Loop until the user closes the window */
//	while (!glfwWindowShouldClose(window))
//	{
//		/* Render here */
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		glBegin(GL_TRIANGLES);
//		glVertex2f(-0.5f,-0.5f);
//		glVertex2f(0.0f, 0.5f);
//		glVertex2f(0.5f, -0.5f);
//		glEnd();
//
//		/* Swap front and back buffers */
//		glfwSwapBuffers(window);
//
//		/* Poll for and process events */
//		glfwPollEvents();
//	}
//
//	glfwTerminate();
//	return 0;
//}
//
//
///*
//int main() {
//	Engine engine = Engine();
//	int index = 0;
//	while ((engine.player1deck.playerDeck).size() > 0) {
//		// COUT
//		// CIN
//		Card player1Card = engine.player1deck.getAndRemoveByIndex(index);
//		cout << player1Card << endl;
//		// COUT
//		// CIN
//		Card player2Card = engine.player2deck.getAndRemoveByIndex(index);
//		cout << player2Card << endl;
//		engine.compare(player1Card, player2Card);
//		cout << engine.player1Score << endl << engine.player2Score << endl;
//	}
//}
//*/