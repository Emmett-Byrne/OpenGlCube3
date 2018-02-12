#include <Game.h>

static bool flip;

Game::Game() : window(VideoMode(800, 600), "OpenGL Cube VBO")
{
}

Game::~Game() {}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		render();
	}

}

void Game::processEvents()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		angleX += 0.01;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		angleX -= 0.01;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		angleY += 0.01;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		angleY -= 0.01;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		scaleX += 0.01;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		scaleX -= 0.01;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		scaleY += 0.01;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		scaleY -= 0.01;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
	{
		transX += 0.01;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
	{
		transX -= 0.01;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
	{
		transY += 0.01;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
	{
		transY -= 0.01;
	}
}

void Game::InitVerts()
{
	vert[0] = MyVector3D(.25f, .25f, .25f); //front top right
	vert[1] = MyVector3D(-.25f, .25f, .25f); //front bottom right
	vert[2] = MyVector3D(-.25f, -.25f, .25f); //front bottom left
	vert[3] = MyVector3D(.25f, -.25f, .25f); //front top left
	vert[4] = MyVector3D(.25f, .25f, -.25f); //back top right
	vert[5] = MyVector3D(-.25f, .25f, -.25f); //back bottom right
	vert[6] = MyVector3D(-.25f, -.25f, -.25f); //back bottom left
	vert[7] = MyVector3D(.25f, -.25f, -.25f); //back top left
}

typedef struct
{
	float coordinate[3];
	float color[3];
} Vert;

Vert vertex[36];
GLubyte triangles[36];

/* Variable to hold the VBO identifier */
GLuint vbo[1];
GLuint index;

void Game::initialize()
{
	isRunning = true;

	glewInit();

	/* Vertices counter-clockwise winding */

	// 0 7 3

	vertex[0].coordinate[0] = vert[0].X();
	vertex[0].coordinate[1] = vert[0].Y();
	vertex[0].coordinate[2] = vert[0].Z();

	vertex[1].coordinate[0] = vert[7].X();
	vertex[1].coordinate[1] = vert[7].Y();
	vertex[1].coordinate[2] = vert[7].Z();

	vertex[2].coordinate[0] = vert[3].X();
	vertex[2].coordinate[1] = vert[3].Y();
	vertex[2].coordinate[2] = vert[3].Z();

	//--

	vertex[3].coordinate[0] = vert[0].X();
	vertex[3].coordinate[1] = vert[0].Y();
	vertex[3].coordinate[2] = vert[0].Z();

	vertex[4].coordinate[0] = vert[4].X();
	vertex[4].coordinate[1] = vert[4].Y();
	vertex[4].coordinate[2] = vert[4].Z();

	vertex[5].coordinate[0] = vert[7].X();
	vertex[5].coordinate[1] = vert[7].Y();
	vertex[5].coordinate[2] = vert[7].Z();

	//--

	vertex[6].coordinate[0] = vert[3].X();
	vertex[6].coordinate[1] = vert[3].Y();
	vertex[6].coordinate[2] = vert[3].Z();

	vertex[7].coordinate[0] = vert[2].X();
	vertex[7].coordinate[1] = vert[2].Y();
	vertex[7].coordinate[2] = vert[2].Z();

	vertex[8].coordinate[0] = vert[1].X();
	vertex[8].coordinate[1] = vert[1].Y();
	vertex[8].coordinate[2] = vert[1].Z();

	//--

	vertex[9].coordinate[0] = vert[3].X();
	vertex[9].coordinate[1] = vert[3].Y();
	vertex[9].coordinate[2] = vert[3].Z();

	vertex[10].coordinate[0] = vert[0].X();
	vertex[10].coordinate[1] = vert[0].Y();
	vertex[10].coordinate[2] = vert[0].Z();

	vertex[11].coordinate[0] = vert[1].X();
	vertex[11].coordinate[1] = vert[1].Y();
	vertex[11].coordinate[2] = vert[1].Z();


	//vertex[3].coordinate[0] = 0.5f; 
	//vertex[3].coordinate[1] = 0.5f;  
	//vertex[3].coordinate[2] = 0.0f;

	//vertex[4].coordinate[0] = 0.5f; 
	//vertex[4].coordinate[1] = -0.5f;  
	//vertex[4].coordinate[2] = 0.0f;

	//vertex[5].coordinate[0] = -0.5f; 
	//vertex[5].coordinate[1] = -0.5f;  
	//vertex[5].coordinate[2] = 0.0f;

	vertex[0].color[0] = 0.1f;
	vertex[0].color[1] = 1.0f;
	vertex[0].color[2] = 0.0f;

	vertex[1].color[0] = 0.2f;
	vertex[1].color[1] = 1.0f;
	vertex[1].color[2] = 0.0f;

	vertex[2].color[0] = 0.3f;
	vertex[2].color[1] = 1.0f;
	vertex[2].color[2] = 0.0f;

	vertex[3].color[0] = 0.4f;
	vertex[3].color[1] = 1.0f;
	vertex[3].color[2] = 0.0f;

	vertex[4].color[0] = 0.5f;
	vertex[4].color[1] = 1.0f;
	vertex[4].color[2] = 0.0f;

	vertex[5].color[0] = 0.6f;
	vertex[5].color[1] = 1.0f;
	vertex[5].color[2] = 0.0f;

	vertex[6].color[0] = 0.6f;
	vertex[6].color[1] = 1.0f;
	vertex[6].color[2] = 0.0f;

	vertex[7].color[0] = 0.6f;
	vertex[7].color[1] = 1.0f;
	vertex[7].color[2] = 0.0f;

	vertex[8].color[0] = 0.6f;
	vertex[8].color[1] = 1.0f;
	vertex[8].color[2] = 0.0f;


	triangles[0] = 0;   triangles[1] = 1;   triangles[2] = 2;
	triangles[3] = 3;   triangles[4] = 4;   triangles[5] = 5;
	triangles[6] = 6;   triangles[7] = 7;   triangles[8] = 8;
	triangles[9] = 9;   triangles[10] = 10;   triangles[11] = 11;
	triangles[12] = 12;   triangles[13] = 13;   triangles[14] = 14;
	triangles[15] = 15;   triangles[16] = 16;   triangles[17] = 17;
	triangles[18] = 18;   triangles[19] = 19;   triangles[20] = 20;
	triangles[21] = 21;   triangles[22] = 22;   triangles[23] = 23;
	triangles[24] = 24;   triangles[25] = 25;   triangles[26] = 26;
	triangles[27] = 27;   triangles[28] = 28;   triangles[29] = 29;
	triangles[30] = 30;   triangles[31] = 31;   triangles[32] = 32;
	triangles[33] = 33;   triangles[34] = 34;   triangles[35] = 35;

	/* Create a new VBO using VBO id */
	glGenBuffers(1, vbo);

	/* Bind the VBO */
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);

	/* Upload vertex data to GPU */
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vert) * 36, vertex, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &index);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLubyte) * 36, triangles, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Game::update()
{
	elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() >= 1.0f)
	{
		clock.restart();

		if (!flip)
		{
			flip = true;
		}
		else
			flip = false;
	}

	if (flip)
	{
		rotationAngle += 0.005f;

		if (rotationAngle > 360.0f)
		{
			rotationAngle -= 360.0f;
		}
	}

	//Change vertex data
	vertex[0].coordinate[0] += -0.0001f;
	vertex[0].coordinate[1] += -0.0001f;
	vertex[0].coordinate[2] += -0.0001f;

	cout << "Update up" << endl;
}

void Game::render()
{
	cout << "Drawing" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index);

	/*	As the data positions will be updated by the this program on the
		CPU bind the updated data to the GPU for drawing	*/
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vert) * 36, vertex, GL_STATIC_DRAW);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);


	glColorPointer(3, GL_FLOAT, sizeof(Vert), (char*)NULL + 12);

	/*	Draw Triangle from VBO	(set where to start from as VBO can contain 
		model compoents that are and are not to be drawn )	*/
	glVertexPointer(3, GL_FLOAT, sizeof(Vert), (char*)NULL + 0);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, (char*)NULL + 0);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;

	glDeleteBuffers(1, vbo);
}

