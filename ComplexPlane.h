#ifndef COMPLEXPLANE_H 
#define COMPLEXPLANE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <complex>
#include <vector>
#include <sstream>
#include <thread>
#include <iomanip>

using namespace sf;
using namespace std;

const unsigned int MAX_ITER = 64;
const float BASE_WIDTH = 4.0;
const float BASE_HEIGHT = 4.0;
const float BASE_ZOOM = 0.5;

enum State { CALCULATING, DISPLAYING };

class ComplexPlane : public sf::Drawable
{
public:
	ComplexPlane(int pixelWidth, int pixelHeight);
	void draw(RenderTarget& target, RenderStates states) const override;
	void zoomIn();
	void zoomOut();
	void setCenter(Vector2i mousePixel);
	void setMouseLocation(Vector2i mousePixel);
	void loadText(Text& text);
	void updateRender();
private:
	VertexArray m_vArray;
	State m_state;
	Vector2f m_mouseLocation;
	Vector2i m_pixel_size;
	Vector2f m_plane_center;
	Vector2f m_plane_size;
	int m_zoomCount;
	float m_aspectRatio;
	int countIterations(Vector2f coord);
	void iterationsToRGB(size_t count, Uint8& r, Uint8& g, Uint8& b);
	Vector2f mapPixelToCoords(Vector2i mousePixel);
};
#endif 
