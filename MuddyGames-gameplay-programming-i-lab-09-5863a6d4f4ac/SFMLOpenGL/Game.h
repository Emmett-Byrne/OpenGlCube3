#include <iostream>
#include <GL/glew.h>
#include <GL/wglew.h>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include "MyMatrix3.h"
#include "MyVector3D.h"

using namespace std;
using namespace sf;

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	void processEvents();
	void InitVerts();
	void setPoint(int v, int p);
	void setPoints();
	void setColour(int v, float r, float g, float b);

	Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void render();
	void unload();

	Clock clock;
	Time elapsed;

	float angleX = 0.0f;
	float angleY = 0.0f;

	float scaleX = 100;
	float scaleY = 100;

	float transX = 0.0f;
	float transY = 0.0f;

	float rotationAngle = 0.0f;
	MyVector3D vert[8];
};

