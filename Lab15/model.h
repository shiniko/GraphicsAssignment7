//FileName:		Model.h
//Programmer:	Keely Canniff, Jamie Lynn Culilap, and Naomi Nunis
//Date:			4/20/2015
//Purpose:		This file defines the header for the WorldModel class.
//This Model class differs from ones in previous labs in that it is responsible for loading the shaders and 
//rendering all of the objects in their proper places. Basically, OpenGL and GLEW stuff goes in this class.
//SDL goes in the Viewcontroller. The Viewcontroller then passes the view_matrix to the draw() method of this class.

#ifndef WORLDMODEL_H
#define WORLDMODEL_H

#include <glew.h> //glew.h is supposed to be included before gl.h. To be safe, you can just include glew.h instead
#include <glm.hpp>
#include "quad.h"
#include "transparentTexModel.h"
#include "PickUpObjectHideBedroom1.h"
#include "multiTexModel.h"
#include "pointSprite.h"
#include "shaderModel.h"
#include "cube.h"
#include "cubeImport.h"
#include "PickUpObject1.h"
#include "rectangle.h"
using namespace glm;

class Model
{
protected:
	bool initialized;

	GLuint program;

	//Variables for matrix manipulations
	mat4 model_matrix;
	mat4 view_matrix;
	mat4 projection_matrix;
	GLuint matrixLoc;

	//Define the objects we want to render in our scene
	TransparentTexModel tree;
	TransparentTexModel plant;
	TransparentTexModel plantFruit1;
	TransparentTexModel plantFruit2;
	TransparentTexModel plantFruit3;
	TransparentTexModel bush;
	TransparentTexModel ceilingLight;
	TransparentTexModel door;
	TransparentTexModel fireplace;
	TransparentTexModel carpet;
	MultiTexModel aCarpet;
	MultiTexModel aWindow;
	MultiTexModel wallNorth;
	MultiTexModel wallEast;
	MultiTexModel wallWest;
	MultiTexModel wallSouth;
	MultiTexModel bedRoomWallNorthEast1;
	MultiTexModel bedRoomWallNorthEast2;
	MultiTexModel bedRoomWallNorthWest1;
	MultiTexModel bedRoomWallNorthWest2;
	MultiTexModel ceiling;

	PointSprite p;
	ShaderModel <Quad> ground;
	ShaderModel <Quad> wall;
	ShaderModel <Cube> brick;
	ShaderModel <CubeImport> importBrick;
	ShaderModel <PickUpObjectHideBedroom1> HideCubes [20];
	ShaderModel <PickUpObject1> pickUp1;
	ShaderModel <Cube> cube;
	ShaderModel <Rectangle> filter;
	void placeTrees(float x, float z);

	int bedRoomCubeNum = 9;

	GLuint brickNoiseTexID;
	GLint numTexLoc;

	float cube_rot_angle;

	//Variables used to control the overdraw filter
	bool filterToggle;
	GLuint filterTexID;
	GLuint clearFilterTexID;

	float degreesToRadians(float degrees) { return (degrees * (3.14159 / 180.0)); }

	int totalNumOfItems = 4; // 0 is the block, 1 is plantFruit1, 2 ia plantFruit2, 3 is plantFruit3
	bool items[4]; //index 0 is the first cube i put in the room
	void drawPlants();
public:
	Model();
	void setItemIndexToFalse(int num);
	bool getItemIndex(int num);
	void setUpLights();
	void setUpBrickTex();
	void setUpBrickTexImport();
	void setUpFilter();
	void setViewMatrix(const mat4 &view_matrixIN) { view_matrix = view_matrixIN; }
	void toggleFilter();

	void updateMatrices();
	void updateWorld();

	bool initGLEW();
	bool init();  //initializes the model
	void draw();  //renders the model
	void decorate();
	void drawBedroom1();
};

#endif