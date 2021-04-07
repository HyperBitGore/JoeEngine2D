#include "JoeEngine.h"
#include <Windows.h>

struct Entity {
	float x;
	float y;
};
Entity player = { 0.0f, 0.0f };
bool exitf = false;
joe::Sprite test;

joe::JoeEngine2D jo;
void render() {
	float delta = jo.getDelta();
	//std::cout << delta << std::endl;
	jo.Clear(0.0f, 0.0f, 0.0f, 1.0f);
	//jo.drawSquare(player.x, player.y, 27.0f, 196.0f, 134.0f, 500.0f);
	//jo.drawSquare(-10.0f, 10.0f, 255.0f, 0.0f, 0.0f, 1.0f);
	jo.drawTriangle(200.0f, -200.0f, 100.0f, 100.0f, 100.0f, 100.0f);
	//jo.drawCircle(-100.0f, 200.0f, 80.0f, 50.0f, 255.0f, 0.0f, 0.0f);
	//jo.SetPixel(-10.0f, 10.0f, 255.0f, 0.0f, 0.0f);
	//jo.SetPixel(-11.0f, 10.0f, 255.0f, 0.0f, 0.0f);
	//jo.SetPixel(-12.0f, 10.0f, 255.0f, 0.0f, 0.0f);
	//jo.drawSprite(test.raw, 30, 100, player.x, player.y);
	jo.drawScreen();
	joe::Pixel color = jo.GetPixelColor(100,200);
	//std::cout << "R: "<< color.data[0] << " B:" << color.data[1] << " G:" << color.data[2] << std::endl;
}

void inputThread() {
	while (!exitf) {
		if (GetAsyncKeyState(VK_UP)) {
			player.y+=2.0f;
		}
		if (GetAsyncKeyState(VK_DOWN)) {
			player.y -= 2.0f;
		}
		if (GetAsyncKeyState(VK_LEFT)) {
			player.x -= 2.0f;
		}
		if (GetAsyncKeyState(VK_RIGHT)) {
			player.x += 2.0f;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(20));
	}
}
int main(int argc, char* argv[]) {
	std::thread input(inputThread);
	SetProcessDPIAware();
	//test.raw = jo.loadPNG(30, 100, "smwall.png", test.raw);
	jo.init(argc, argv, render, 800, 600);
	input.join();
	return 0;

}