#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include "Renderer.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "Texture.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw_gl3.h"
#include "Engine.h"

tuple<double, double> mousePositionClick;
bool inWindow = false;
bool DEBUG = false;
bool contextChange = true;
int nbCardPlayerHand = 13;
//list<string> names = {"2_of_clubs", "2_of_diamonds", "2_of_hearts", "2_of_clubs", "2_of_diamonds", "2_of_hearts", "2_of_clubs", "2_of_diamonds", "2_of_hearts", "2_of_clubs", "2_of_diamonds", "2_of_hearts", "2_of_clubs"};
//list<Texture> textures = {};
//list<string> names = { "2_of_clubs", "3_of_clubs", "4_of_clubs", "5_of_clubs", "6_of_clubs", "7_of_clubs", "8_of_clubs", "9_of_clubs", "10_of_clubs" };

int getCardIndex(tuple<double, double> mousePos);
int getCardNumber(Card card);

static void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos) {
	mousePositionClick = make_tuple(xpos, ypos);
}
void cursorEnterCallback(GLFWwindow* window, int entered) {
	inWindow = entered == 1;
}
void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
	if (inWindow && button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
		int cardIndex = getCardIndex(mousePositionClick);
		//cout << get<0>(mousePositionClick) << " " << get<1>(mousePositionClick) << endl;
		cout << cardIndex << endl;
	}
}

int main(void) {
	GLFWwindow* window;

	if (!glfwInit()) {
		return -1;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwSetCursorPosCallback(window, cursorPositionCallback);
	glfwSetCursorEnterCallback(window, cursorEnterCallback);
	glfwSetMouseButtonCallback(window, mouseButtonCallback);

	glfwMakeContextCurrent(window);

	glfwSwapInterval(1);

	if (glewInit() != GLEW_OK)
		cout << "error" << endl;

	cout << glGetString(GL_VERSION) << endl;
	{
		//float positions[] = {
		//	-0.5f, -0.5f, 0.0f, 0.0f,
		//	0.5f, -0.5f, 1.0f, 0.0f,
		//	0.5f, 0.5f, 1.0f, 1.0f,
		//	-0.5f, 0.5f, 0.0f, 1.0f
		//};

		//float positions[] = {
		//	100.0f, 100.0f, 0.0f, 0.0f,
		//	200.0f, 100.0f, 1.0f, 0.0f,
		//	200.0f, 200.0f, 1.0f, 1.0f,
		//	100.0f, 200.0f, 0.0f, 1.0f
		//};

		float positions[] = {
			-50.0f, -50.0f, 0.0f, 0.0f,
			50.0f, -50.0f, 1.0f, 0.0f,
			50.0f, 50.0f, 1.0f, 1.0f,
			-50.0f, 50.0f, 0.0f, 1.0f
		};

		unsigned int indices[] = {
			0,1,2,
			2,3,0
		};

		GLCall(glEnable(GL_BLEND));
		GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

		VertexArray va;
		VertexBuffer vb(positions, 4 * 4 * sizeof(float));
		
		VertexBufferLayout layout;
		layout.Push<float>(2);
		layout.Push<float>(2);
		va.AddBuffer(vb, layout);

		IndexBuffer ib(indices, 6);

		//double factor = 2;
		//float xValue = 640.0f;
		//float yValue = 480.0f;
		//xValue = xValue * factor;
		//yValue = yValue * factor;
		//glm::mat4 proj = glm::ortho(0.0f, xValue, 0.0f, yValue, -1.0f, 1.0f);

		//glm::mat4 proj = glm::ortho(-2.0f, 2.0f, -1.5f, 1.5f, -1.0f, 1.0f);
		// "Move camera"
		glm::mat4 proj = glm::ortho(0.0f, 640.0f, 0.0f, 480.0f, -1.0f, 1.0f);
		glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));
		//glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(200, 200, 0));
		//glm::mat4 mvp = proj * view * model;

		/*glm::vec4 vp(100.0f, 100.0f, 0.0f, 1.0f);
		glm::vec4 result = proj*vp;*/


		Shader shader("res/shaders/Basic.shader");
		shader.Bind();
		shader.SetUniform4f("u_Color", 0.8f, 0.4f, 0.8f, 1.0f);
		/*shader.SetUniformMat4f("u_MVP", mvp);*/

		Texture texture1("res/textures/cards/ace_of_hearts.png");
		Texture texture2("res/textures/cards/2_of_hearts.png");
		Texture texture3("res/textures/cards/3_of_hearts.png");
		Texture texture4("res/textures/cards/4_of_hearts.png");
		Texture texture5("res/textures/cards/5_of_hearts.png");
		Texture texture6("res/textures/cards/6_of_hearts.png");
		Texture texture7("res/textures/cards/7_of_hearts.png");
		Texture texture8("res/textures/cards/8_of_hearts.png");
		Texture texture9("res/textures/cards/9_of_hearts.png");
		Texture texture10("res/textures/cards/10_of_hearts.png");
		Texture texture11("res/textures/cards/jack_of_hearts.png");
		Texture texture12("res/textures/cards/queen_of_hearts.png");
		Texture texture13("res/textures/cards/king_of_hearts.png");

		Texture texture14("res/textures/cards/ace_of_clubs.png");
		Texture texture15("res/textures/cards/2_of_clubs.png");
		Texture texture16("res/textures/cards/3_of_clubs.png");
		Texture texture17("res/textures/cards/4_of_clubs.png");
		Texture texture18("res/textures/cards/5_of_clubs.png");
		Texture texture19("res/textures/cards/6_of_clubs.png");
		Texture texture20("res/textures/cards/7_of_clubs.png");
		Texture texture21("res/textures/cards/8_of_clubs.png");
		Texture texture22("res/textures/cards/9_of_clubs.png");
		Texture texture23("res/textures/cards/10_of_clubs.png");
		Texture texture24("res/textures/cards/jack_of_clubs.png");
		Texture texture25("res/textures/cards/queen_of_clubs.png");
		Texture texture26("res/textures/cards/king_of_clubs.png");

		Texture texture27("res/textures/cards/ace_of_spades.png");
		Texture texture28("res/textures/cards/2_of_spades.png");
		Texture texture29("res/textures/cards/3_of_spades.png");
		Texture texture30("res/textures/cards/4_of_spades.png");
		Texture texture31("res/textures/cards/5_of_spades.png");
		Texture texture32("res/textures/cards/6_of_spades.png");
		Texture texture33("res/textures/cards/7_of_spades.png");
		Texture texture34("res/textures/cards/8_of_spades.png");
		Texture texture35("res/textures/cards/9_of_spades.png");
		Texture texture36("res/textures/cards/10_of_spades.png");
		Texture texture37("res/textures/cards/jack_of_spades.png");
		Texture texture38("res/textures/cards/queen_of_spades.png");
		Texture texture39("res/textures/cards/king_of_spades.png");

		Texture texture40("res/textures/cards/ace_of_diamonds.png");
		Texture texture41("res/textures/cards/2_of_diamonds.png");
		Texture texture42("res/textures/cards/3_of_diamonds.png");
		Texture texture43("res/textures/cards/4_of_diamonds.png");
		Texture texture44("res/textures/cards/5_of_diamonds.png");
		Texture texture45("res/textures/cards/6_of_diamonds.png");
		Texture texture46("res/textures/cards/7_of_diamonds.png");
		Texture texture47("res/textures/cards/8_of_diamonds.png");
		Texture texture48("res/textures/cards/9_of_diamonds.png");
		Texture texture49("res/textures/cards/10_of_diamonds.png");
		Texture texture50("res/textures/cards/jack_of_diamonds.png");
		Texture texture51("res/textures/cards/queen_of_diamonds.png");
		Texture texture52("res/textures/cards/king_of_diamonds.png");

		Texture cardTextureArray[52] = { texture1, texture2, texture3, texture4, texture5, texture6, texture7, texture8, texture9, texture10, texture11, texture12, texture13, texture14, texture15, texture16, texture17, texture18, texture19, texture20, texture21, texture22, texture23, texture24, texture25, texture26, texture27, texture28, texture29, texture30, texture31, texture32, texture33, texture34, texture35, texture36, texture37, texture38, texture39, texture40, texture41, texture42, texture43, texture44, texture45, texture46, texture47, texture48, texture49, texture50, texture51, texture52 };

		va.Unbind();
		vb.Unbind();
		ib.Unbind();
		shader.Unbind();

		Renderer renderer;

		if (DEBUG) {
			ImGui::CreateContext();
			ImGui_ImplGlfwGL3_Init(window, true);
			ImGui::StyleColorsDark();
		}

		glm::vec3 translationA(50, 200, 0);
		glm::vec3 translationB(150, 200, 0);

		float r = 0.0f;
		float increment = 0.05f;

		while (!glfwWindowShouldClose(window))
		{
			renderer.Clear();

			if (DEBUG) {
				ImGui_ImplGlfwGL3_NewFrame();
			}

			shader.Bind();

			float r = 0.0f;
			float increment = 0.05f;

			if (DEBUG) {
				texture1.Bind();
				glm::mat4 model1 = glm::translate(glm::mat4(1.0f), translationA);
				glm::mat4 mvp1 = proj * view * model1;
				shader.SetUniformMat4f("u_MVP", mvp1);
				renderer.Draw(va, ib, shader);

				texture2.Bind();
				glm::mat4 model2 = glm::translate(glm::mat4(1.0f), translationB);
				glm::mat4 mvp2 = proj * view * model2;
				shader.SetUniformMat4f("u_MVP", mvp2);
				renderer.Draw(va, ib, shader);
			}
			else {
				int counter = 0;
				int yPos = 400;
				int xPos = 50;
				glm::vec3 translation(xPos, yPos, 0);

				nbCardPlayerHand = 13;
				for (int i = 0; i < nbCardPlayerHand; i++) {
					cardTextureArray[i].Bind();
					shader.SetUniform1i("u_Texture", 0);

					if (counter % 5 == 0 && counter != 0) {
						yPos -= 100;
						xPos = 50;
					}
					glm::vec3 translation(xPos, yPos, 0);
					glm::mat4 model = glm::translate(glm::mat4(1.0f), translation);
					glm::mat4 mvp = proj * view * model;
					shader.SetUniformMat4f("u_MVP", mvp);
					renderer.Draw(va, ib, shader);
					counter++;
					xPos += 100;
				}
			}

			if (DEBUG) {
				{
					ImGui::SliderFloat3("Translation A", &translationA.x, 0.0f, 540.0f);
					ImGui::SliderFloat3("Translation B", &translationB.x, 0.0f, 540.0f);
					ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
				}

				ImGui::Render();
				ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());
			}
			
			///* Swap front and back buffers */
			glfwSwapBuffers(window);

			///* Poll for and process events */
			glfwPollEvents();
		}
	}
	if (DEBUG) {
		ImGui_ImplGlfwGL3_Shutdown();
		ImGui::DestroyContext();
	}
	glfwTerminate();
	return 0;
}

int getCardNumber(Card card) {
	int factor = 0;
	if (card.suit == "Clubs") {
		factor = 1;
	}
	else if (card.suit == "Spades") {
		factor = 2;
	}
	else if (card.suit == "Diamonds") {
		factor = 3;
	}
	int number = 1;
	if (card.value.value == "2") {
		number = 2;
	}
	else if (card.value.value == "3") {
		number = 3;
	}
	else if (card.value.value == "4") {
		number = 4;
	}
	else if (card.value.value == "5") {
		number = 5;
	}
	else if (card.value.value == "6") {
		number = 6;
	}
	else if (card.value.value == "7") {
		number = 7;
	}
	else if (card.value.value == "8") {
		number = 8;
	}
	else if (card.value.value == "9") {
		number = 9;
	}
	else if (card.value.value == "10") {
		number = 10;
	}
	else if (card.value.value == "J") {
		number = 11;
	}
	else if (card.value.value == "Q") {
		number = 12;
	}
	else if (card.value.value == "K") {
		number = 13;
	}
	return 13 * factor + number - 1;
}

int getCardIndex(tuple<double, double> mouseClickPosition) {
	//if (get<0>(mousePositionClick) >= 25 && get<0>(mousePositionClick) <= (((nbCardPlayerHand/5) + 1) * 100) + 25) && get<0>
	int x = 0;
	int y = 0;
	if (get<1>(mousePositionClick) >= 125 && get<1>(mousePositionClick) <= 225) {
		y = 1;
	}
	else if (get<1>(mousePositionClick) >= 225 && get<1>(mousePositionClick) <= 325) {
		y = 2;
	}

	x = get<0>(mousePositionClick) / 100;

	return 5 * y + x;
}