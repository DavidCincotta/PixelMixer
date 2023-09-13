#shader vertex
#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 texCoord;

out vec2 v_fragCoord;

uniform mat4 u_MVP;

void main() {
   gl_Position = u_MVP * position;
   v_fragCoord = texCoord;
}





#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

in vec2 v_fragCoord;
uniform sampler2D u_Texture;
uniform int u_Frame;
uniform vec2 u_Resolution;

// Get luminance of color
float Lum(vec4 c) { return dot(c.rgb, vec3(0.299, 0.587, 0.114)); }

void main() {
    vec2 uv = v_fragCoord; // / u_Resolution;
    vec2 texel = 1. / textureSize(u_Texture, 0);
    float step_y = texel.y;
    vec2 s = vec2(0.0, -step_y);
    vec2 n = vec2(0.0, step_y);

    vec4 texColor_n = texture(u_Texture, uv + n);
    vec4 texColor = texture(u_Texture, uv);
    vec4 texColor_s = texture(u_Texture, uv + s);

    float luminance_n = Lum(texColor_n);
    float luminance = Lum(texColor);
    float luminance_s = Lum(texColor_s);

    if (int(mod(float(u_Frame) + gl_FragCoord.y, 2.0)) == 0) {
        if (luminance_s > luminance) {
            texColor = texColor_s;
        }
    } else {
        if (luminance_n < luminance) {
            texColor = texColor_n;
        }
    }
    gl_FragColor = texColor;
}