#pragma once

#include "Renderer.h"
using namespace std;

class Texture {
private :
	unsigned int m_RendererID;
	string m_FilePath;
	unsigned char* m_LocalBuffer;
	int m_Width, m_Height, m_BPP;
public :
	Texture(const string& path);
	~Texture();

	void Bind(unsigned int slot = 0) const;
	void Unbind() const;

	inline int getWidth() const { return m_Width; }
	inline int getHeight() const { return m_Height; }
};