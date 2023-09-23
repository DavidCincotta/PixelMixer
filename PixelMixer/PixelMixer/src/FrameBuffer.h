#pragma once
#include "vendor/glm/glm.hpp"

class FrameBuffer
{
public:
    FrameBuffer(unsigned int width, unsigned int height);
    ~FrameBuffer();

    inline unsigned int GetFBO() const { return RendererID_; }
    inline unsigned int GetTexture() const { return TextureID_; }
    inline unsigned int GetRBO() const { return RenderBufferID_; }
    inline void GetSize(unsigned int& w, unsigned int& h) { w = Width_; h = Height_; }
    inline void SetClearColor(float r, float g, float b, float a) { ClearColor_ = glm::vec4(r,g,b,a); }
    inline void GetClearColor(float& r, float& g, float& b, float& a) { r = ClearColor_.x; g = ClearColor_.y; b = ClearColor_.z; a = ClearColor_.w; }

private:
    unsigned int RendererID_;
    unsigned int TextureID_;
    unsigned int RenderBufferID_;
    unsigned int Width_, Height_;
    glm::vec4 ClearColor_;
    
};