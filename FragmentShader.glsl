#version 330 core

in vec3 frag_position;
in vec3 frag_normal;
in vec2 frag_texture_coord;
in vec3 frag_color;

out vec4 out_color;

uniform vec3 color;

void main()
{
    out_color = vec4(color, 1.0);
}
