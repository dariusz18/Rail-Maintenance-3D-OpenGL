#include "lab_m1/tema2/tema2.h"
#include <vector>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;
using namespace m1;

Tema2::Tema2()
{
}

Tema2::~Tema2()
{
}

Mesh* Tema2::Create_mesh(const char* name, const std::vector<VertexFormat>& vertices, const std::vector<unsigned int>& indices)
{
    unsigned int VAO = 0;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0]) * vertices.size(), &vertices[0], GL_STATIC_DRAW);

    unsigned int IBO;
    glGenBuffers(1, &IBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices[0]) * indices.size(), &indices[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), 0);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(sizeof(glm::vec3)));

    glBindVertexArray(0);

    CheckOpenGLError();

    meshes[name] = new Mesh(name);
    meshes[name]->InitFromBuffer(VAO, static_cast<unsigned int>(indices.size()));
    meshes[name]->vertices = vertices;
    meshes[name]->indices = indices;

    return meshes[name];
}

void Tema2::Init()
{
    {
        vector<VertexFormat> quad_verts = {
            VertexFormat(glm::vec3(-0.5f, 0.0f, -0.5f), glm::vec3(0, 1, 0)),
            VertexFormat(glm::vec3(0.5f, 0.0f, -0.5f), glm::vec3(0, 1, 0)),
            VertexFormat(glm::vec3(0.5f, 0.0f, 0.5f), glm::vec3(0, 1, 0)),
            VertexFormat(glm::vec3(-0.5f, 0.0f, 0.5f), glm::vec3(0, 1, 0)),
        };
        vector<unsigned int> quad_ind = { 0, 1, 2, 0, 2, 3 };
        Create_mesh("quad", quad_verts, quad_ind);
    }

    {
        vector<VertexFormat> track_verts = {
            VertexFormat(glm::vec3(-0.5f, 0.0f, -0.1f), glm::vec3(0, 1, 0)),
            VertexFormat(glm::vec3(0.5f, 0.0f, -0.1f), glm::vec3(0, 1, 0)),
            VertexFormat(glm::vec3(0.5f, 0.0f, 0.1f), glm::vec3(0, 1, 0)),
            VertexFormat(glm::vec3(-0.5f, 0.0f, 0.1f), glm::vec3(0, 1, 0)),
        };
        vector<unsigned int> track_ind = { 0, 1, 2, 0, 2, 3 };
        Create_mesh("track", track_verts, track_ind);
    }

    {
        vector<VertexFormat> box_verts = {
            VertexFormat(glm::vec3(-0.5f, 0.0f, -0.5f), glm::vec3(0, 0, -1)),
            VertexFormat(glm::vec3(0.5f, 0.0f, -0.5f), glm::vec3(0, 0, -1)),
            VertexFormat(glm::vec3(0.5f, 1.0f, -0.5f), glm::vec3(0, 0, -1)),
            VertexFormat(glm::vec3(-0.5f, 1.0f, -0.5f), glm::vec3(0, 0, -1)),
            VertexFormat(glm::vec3(-0.5f, 0.0f, 0.5f), glm::vec3(0, 0, 1)),
            VertexFormat(glm::vec3(0.5f, 0.0f, 0.5f), glm::vec3(0, 0, 1)),
            VertexFormat(glm::vec3(0.5f, 1.0f, 0.5f), glm::vec3(0, 0, 1)),
            VertexFormat(glm::vec3(-0.5f, 1.0f, 0.5f), glm::vec3(0, 0, 1)),
            VertexFormat(glm::vec3(-0.5f, 0.0f, 0.5f), glm::vec3(-1, 0, 0)),
            VertexFormat(glm::vec3(-0.5f, 0.0f, -0.5f), glm::vec3(-1, 0, 0)),
            VertexFormat(glm::vec3(-0.5f, 1.0f, -0.5f), glm::vec3(-1, 0, 0)),
            VertexFormat(glm::vec3(-0.5f, 1.0f, 0.5f), glm::vec3(-1, 0, 0)),
            VertexFormat(glm::vec3(0.5f, 0.0f, -0.5f), glm::vec3(1, 0, 0)),
            VertexFormat(glm::vec3(0.5f, 0.0f, 0.5f), glm::vec3(1, 0, 0)),
            VertexFormat(glm::vec3(0.5f, 1.0f, 0.5f), glm::vec3(1, 0, 0)),
            VertexFormat(glm::vec3(0.5f, 1.0f, -0.5f), glm::vec3(1, 0, 0)),
            VertexFormat(glm::vec3(-0.5f, 1.0f, -0.5f), glm::vec3(0, 1, 0)),
            VertexFormat(glm::vec3(0.5f, 1.0f, -0.5f), glm::vec3(0, 1, 0)),
            VertexFormat(glm::vec3(0.5f, 1.0f, 0.5f), glm::vec3(0, 1, 0)),
            VertexFormat(glm::vec3(-0.5f, 1.0f, 0.5f), glm::vec3(0, 1, 0)),
            VertexFormat(glm::vec3(-0.5f, 0.0f, 0.5f), glm::vec3(0, -1, 0)),
            VertexFormat(glm::vec3(0.5f, 0.0f, 0.5f), glm::vec3(0, -1, 0)),
            VertexFormat(glm::vec3(0.5f, 0.0f, -0.5f), glm::vec3(0, -1, 0)),
            VertexFormat(glm::vec3(-0.5f, 0.0f, -0.5f), glm::vec3(0, -1, 0)),
        };
        vector<unsigned int> box_ind = {
            0, 1, 2, 0, 2, 3,
            4, 6, 5, 4, 7, 6,
            8, 9, 10, 8, 10, 11,
            12, 14, 13, 12, 15, 14,
            16, 17, 18, 16, 18, 19,
            20, 22, 21, 20, 23, 22
        };
        Create_mesh("box", box_verts, box_ind);
    }

    {
        vector<VertexFormat> cylinder_verts;
        vector<unsigned int> cylinder_ind;

        int segments = 25;
        float radius = 0.25f;
        float height = 1.0f;

        cylinder_verts.push_back(VertexFormat(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0, -1, 0)));
        for (int i = 0; i <= segments; ++i) {
            float theta = 2.0f * glm::pi<float>() * i / segments;
            float x = radius * cos(theta);
            float z = radius * sin(theta);
            cylinder_verts.push_back(VertexFormat(glm::vec3(x, 0.0f, z), glm::vec3(0, -1, 0)));
        }

        cylinder_verts.push_back(VertexFormat(glm::vec3(0.0f, height, 0.0f), glm::vec3(0, 1, 0)));
        for (int i = 0; i <= segments; ++i) {
            float theta = 2.0f * glm::pi<float>() * i / segments;
            float x = radius * cos(theta);
            float z = radius * sin(theta);
            cylinder_verts.push_back(VertexFormat(glm::vec3(x, height, z), glm::vec3(0, 1, 0)));
        }

        for (int i = 0; i <= segments; ++i) {
            float theta = 2.0f * glm::pi<float>() * i / segments;
            float x = cos(theta);
            float z = sin(theta);
            cylinder_verts.push_back(VertexFormat(glm::vec3(radius * x, 0.0f, radius * z), glm::vec3(x, 0, z)));
            cylinder_verts.push_back(VertexFormat(glm::vec3(radius * x, height, radius * z), glm::vec3(x, 0, z)));
        }

        for (int i = 1; i <= segments; ++i) {
            cylinder_ind.push_back(0);
            cylinder_ind.push_back(i + 1);
            cylinder_ind.push_back(i);
        }

        int top_center = segments + 2;
        for (int i = 1; i <= segments; ++i) {
            cylinder_ind.push_back(top_center);
            cylinder_ind.push_back(top_center + i);
            cylinder_ind.push_back(top_center + i + 1);
        }

        int side_start = 2 * (segments + 2);
        for (int i = 0; i < segments; ++i) {
            int base = side_start + i * 2;
            cylinder_ind.push_back(base);
            cylinder_ind.push_back(base + 1);
            cylinder_ind.push_back(base + 2);

            cylinder_ind.push_back(base + 1);
            cylinder_ind.push_back(base + 3);
            cylinder_ind.push_back(base + 2);
        }

        Create_mesh("cylinder", cylinder_verts, cylinder_ind);
    }

    {
        vector<VertexFormat> pyramid_verts = {
            VertexFormat(glm::vec3(-0.5f, 0.0f, -0.5f), glm::vec3(0, -1, 0)),
            VertexFormat(glm::vec3(0.5f, 0.0f, -0.5f), glm::vec3(0, -1, 0)),
            VertexFormat(glm::vec3(0.5f, 0.0f, 0.5f), glm::vec3(0, -1, 0)),
            VertexFormat(glm::vec3(-0.5f, 0.0f, 0.5f), glm::vec3(0, -1, 0)),
            VertexFormat(glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0, 1, 0)),
        };

        vector<unsigned int> pyramid_ind = {
            0, 2, 1, 0, 3, 2,
            0, 1, 4,
            1, 2, 4,
            2, 3, 4,
            3, 0, 4
        };

        Create_mesh("pyramid", pyramid_verts, pyramid_ind);
    }

    {
        Shader* shader = new Shader("TerrainShader");
        shader->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "tema2", "shaders", "VertexShader.glsl"), GL_VERTEX_SHADER);
        shader->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "tema2", "shaders", "FragmentShader.glsl"), GL_FRAGMENT_SHADER);
        shader->CreateAndLink();
        shaders[shader->GetName()] = shader;
    }

    camera = new implemented::Camera();
    camera->Set(glm::vec3(15.0f, 40.0f, 15.0f), glm::vec3(0, 1, 0), glm::vec3(0, 1, 0));

    fov = 60.0f;
    zNear = 0.01f;
    zFar = 200.0f;

    lifes_express = 1;
    map_w = 10;
    map_h = 10;
    cell_size = 2.0f;
    Generate_terrain(map_w, map_h);
    Init_rail_path();
    Generate_track_segments();

    cur_seg = 0;
    train_prog = 0.0f;
    train_speed = 1.5f;
    train_pos = rail_path[0].start_pos;
    train_rot = 0.0f;

    express_seg = 15;
    express_prog = 0.5f;
    express_speed = 1.5f;
    express_pos = rail_path[express_seg].start_pos;
    express_rot = 0.0f;

    drezina_pos = glm::vec3(4.0f * cell_size - map_w * cell_size / 2.0f, 0.05f, 8.0f * cell_size - map_h * cell_size / 2.0f);
    drezina_rot = 0.0f;
    drezina_seg_idx = 0;
    drezina_t = 0.0f;
    drezina_speed = 5.0f;
    handle_angle = 0.0f;

    is_ending = false;
    game_over_timer = 0.0f;

    tps_camera = false;
    count_stricate = 0;
    time_until_break = 2.0f;
    game_over = false;

    float t_w = map_w * cell_size;
    float t_h = map_h * cell_size;
    station_pos.clear();
    station_pos.push_back(glm::vec3(2 * cell_size - t_w / 2.0f, 0.0f, 0 * cell_size - t_h / 2.0f));
    station_pos.push_back(glm::vec3(3 * cell_size - t_w / 2.0f + 1.0f, 0.0f, 7 * cell_size - t_h / 2.0f + 0.8f));
    station_pos.push_back(glm::vec3(7 * cell_size - t_w / 2.0f + 2.3f, 0.0f, 3 * cell_size - t_h / 2.0f));

    is_station_stopped = false;
    station_stop_timer = 0.0f;
    last_station_idx = -1;
    total_time = 0.0f;
    glm::ivec2 resolution = window->GetResolution();
    text_renderer = new gfxc::TextRenderer(window->props.selfDir, resolution.x, resolution.y);
    text_renderer->Load(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::FONTS, "Hack-Bold.ttf"), 40);

    express_stop = false;
    express_timer = 0;

    srand((unsigned int)time(NULL));
}

//generare teren
void Tema2::Generate_terrain(int w, int h)
{
    terrain_map.clear();
    terrain_map.resize(w, vector<Terrain_type>(h));

    for (int x = 0; x < w; ++x) {
        for (int z = 0; z < h; ++z) {
            if (x >= 1 && x <= 4 && z >= 0 && z <= 2) {
                terrain_map[x][z] = MOUNTAIN;
            }
            else if ((x == 2 && z >= 4 && z <= 9) || (z == 4 && x >= 2 && x <= 6) || (x == 6 && z >= 1 && z <= 4) || (z == 1 && x >= 6 && x <= 9)) {
                terrain_map[x][z] = WATER;
            }
            else {
                terrain_map[x][z] = PLAIN;
            }
        }
    }
}

//initializare sina
void Tema2::Init_rail_path()
{
    rail_path.clear();

    float ter_w = map_w * cell_size;
    float ter_h = map_h * cell_size;
    float y_off = 0.05f;

    for (int x = 2; x < 8; x++) {
        glm::vec3 start((float)x * cell_size - ter_w / 2.0f, y_off, 8.0f * cell_size - ter_h / 2.0f);
        glm::vec3 end((float)(x + 1) * cell_size - ter_w / 2.0f, y_off, 8.0f * cell_size - ter_h / 2.0f);
        rail_path.push_back({ start, end });
    }

    for (int z = 8; z > 1; z--) {
        glm::vec3 start(8.0f * cell_size - ter_w / 2.0f + 1.5f, y_off, (float)z * cell_size - ter_h / 2.0f);
        glm::vec3 end(8.0f * cell_size - ter_w / 2.0f + 1.5f, y_off, (float)(z - 1) * cell_size - ter_h / 2.0f);
        rail_path.push_back({ start, end });
    }

    for (int x = 8; x > 1; x--) {
        glm::vec3 start((float)x * cell_size - ter_w / 2.0f, y_off, 1.0f * cell_size - ter_h / 2.0f - 0.6f);
        glm::vec3 end((float)(x - 1) * cell_size - ter_w / 2.0f, y_off, 1.0f * cell_size - ter_h / 2.0f - 0.6f);
        rail_path.push_back({ start, end });
    }

    for (int z = 1; z < 8; z++) {
        glm::vec3 start(1.0f * cell_size - ter_w / 2.0f - 0.3f, y_off, (float)z * cell_size - ter_h / 2.0f);
        glm::vec3 end(1.0f * cell_size - ter_w / 2.0f - 0.3f, y_off, (float)(z + 1) * cell_size - ter_h / 2.0f);
        rail_path.push_back({ start, end });
    }

    {
        glm::vec3 start(1.0f * cell_size - ter_w / 2.0f - 0.6f, y_off, 8.0f * cell_size - ter_h / 2.0f);
        glm::vec3 end(2.0f * cell_size - ter_w / 2.0f, y_off, 8.0f * cell_size - ter_h / 2.0f);
        rail_path.push_back({ start, end });
    }

    std::reverse(rail_path.begin(), rail_path.end());

    for (auto& seg : rail_path) {
        std::swap(seg.start_pos, seg.end_pos);
    }
}

//generare segmente
void Tema2::Generate_track_segments()
{
    track_segments.clear();
    float ter_w = map_w * cell_size;
    float ter_h = map_h * cell_size;
    float pos_x, pos_z;
    glm::mat4 model;

    int x = 2;
    int z = 8;
    pos_x = (float)x * cell_size - ter_w / 2.0f;
    pos_z = (float)z * cell_size - ter_h / 2.0f;
    model = glm::mat4(1);
    model = glm::translate(model, glm::vec3(pos_x, 0.05f, pos_z));
    model = glm::scale(model, glm::vec3(cell_size, 0.1f, cell_size + 2));
    track_segments.push_back({ model, false, glm::vec3(1.0f, 0.0f, 0.0f) });


    for (int x = 1; x <= 8; x++) {
        if (x != 2) {
            int z = 8;
            pos_x = (float)x * cell_size - ter_w / 2.0f;
            pos_z = (float)z * cell_size - ter_h / 2.0f;
            model = glm::mat4(1);
            model = glm::translate(model, glm::vec3(pos_x, 0.05f, pos_z));
            model = glm::scale(model, glm::vec3(cell_size, 0.1f, cell_size + 2));
            track_segments.push_back({ model, false, glm::vec3(0.4f, 0.0f, 0.4f) });
        }
    }

    x = 1;
    for (int z = 1; z <= 7; z++) {
        pos_x = (float)x * cell_size - ter_w / 2.0f - 0.6f;
        pos_z = (float)z * cell_size - ter_h / 2.0f;
        model = glm::mat4(1);

        if (z > 2) {
            model = glm::translate(model, glm::vec3(pos_x, 0.05f, pos_z));
            model = glm::rotate(model, RADIANS(90.0f), glm::vec3(0, 1, 0));
            model = glm::scale(model, glm::vec3(cell_size, 0.1f, cell_size + 2));
            track_segments.push_back({ model, false, glm::vec3(0.4f, 0.0f, 0.4f) });
        }
        else if (z <= 2) {
            model = glm::translate(model, glm::vec3(pos_x, 0.05f, pos_z));
            model = glm::rotate(model, RADIANS(90.0f), glm::vec3(0, 1, 0));
            model = glm::scale(model, glm::vec3(cell_size, 0.1f, cell_size + 2));
            track_segments.push_back({ model, false, glm::vec3(1.0f, 1.0f, 1.0f) });
        }
    }


    pos_x = (float)1 * cell_size - ter_w / 2.0f - 0.6f;
    pos_z = (float)7.5 * cell_size - ter_h / 2.0f;
    model = glm::mat4(1);
    model = glm::translate(model, glm::vec3(pos_x, 0.05f, pos_z));
    model = glm::rotate(model, RADIANS(90.0f), glm::vec3(0, 1, 0));
    model = glm::scale(model, glm::vec3(cell_size, 0.1f, cell_size + 2));
    track_segments.push_back({ model, false, glm::vec3(0.4f, 0.0f, 0.4f) });


    for (int x = 1; x <= 8; x++) {
        int z = 1;

        if (x <= 4) {
            pos_x = (float)x * cell_size - ter_w / 2.0f;
            pos_z = (float)z * cell_size - ter_h / 2.0f - 0.6f;
            model = glm::mat4(1);
            model = glm::translate(model, glm::vec3(pos_x, 0.05f, pos_z));
            model = glm::scale(model, glm::vec3(cell_size, 0.1f, cell_size + 2));
            track_segments.push_back({ model, false, glm::vec3(1.0f, 1.0f, 1.0f) });
        }
        else if (x == 5) {
            pos_x = (float)x * cell_size - ter_w / 2.0f;
            pos_z = (float)z * cell_size - ter_h / 2.0f - 0.6f;
            model = glm::mat4(1);
            model = glm::translate(model, glm::vec3(pos_x, 0.05f, pos_z));
            model = glm::scale(model, glm::vec3(cell_size, 0.1f, cell_size + 2));
            track_segments.push_back({ model, false, glm::vec3(0.4f, 0.0f, 0.4f) });
        }
        else if (x >= 6) {
            pos_x = (float)x * cell_size - ter_w / 2.0f;
            pos_z = (float)z * cell_size - ter_h / 2.0f - 0.6f;
            model = glm::mat4(1);
            model = glm::translate(model, glm::vec3(pos_x, 0.05f, pos_z));
            model = glm::scale(model, glm::vec3(cell_size, 0.1f, cell_size + 2));
            track_segments.push_back({ model, false, glm::vec3(1.0f, 0.0f, 0.0f) });
        }
    }


    x = 9;
    for (int z = 1; z <= 8; z++) {
        pos_x = (float)x * cell_size - ter_w / 2.0f - 0.6f;
        pos_z = (float)z * cell_size - ter_h / 2.0f;

        if (z >= 2 && z < 8) {
            model = glm::mat4(1);
            model = glm::translate(model, glm::vec3(pos_x, 0.05f, pos_z - 0.1f));
            model = glm::rotate(model, RADIANS(90.0f), glm::vec3(0, 1, 0));
            model = glm::scale(model, glm::vec3(cell_size, 0.1f, cell_size + 2));
            track_segments.push_back({ model, false, glm::vec3(0.4f, 0.0f, 0.4f) });
        }
        else if (z == 8) {
            model = glm::mat4(1);
            model = glm::translate(model, glm::vec3(pos_x, 0.05f, pos_z - 0.5f));
            model = glm::rotate(model, RADIANS(90.0f), glm::vec3(0, 1, 0));
            model = glm::scale(model, glm::vec3(cell_size * 0.9f, 0.1f, cell_size + 2));
            track_segments.push_back({ model, false, glm::vec3(0.4f, 0.0f, 0.4f) });
        }
        else if (z == 1) {
            model = glm::mat4(1);
            model = glm::translate(model, glm::vec3(pos_x, 0.05f, pos_z));
            model = glm::rotate(model, RADIANS(90.0f), glm::vec3(0, 1, 0));
            model = glm::scale(model, glm::vec3(cell_size, 0.1f, cell_size + 2));
            track_segments.push_back({ model, false, glm::vec3(1.0f, 0.0f, 0.0f) });
        }
    }

}

void Tema2::FrameStart()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();
    glViewport(0, 0, resolution.x, resolution.y);
}

void Tema2::Update(float delta_time)
{
    projectionMatrix = glm::perspective(RADIANS(fov), window->props.aspectRatio, zNear, zFar);

    if (game_over) {
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glm::ivec2 resolution = window->GetResolution();
        glViewport(0, 0, resolution.x, resolution.y);

        float text_scale = 2.0f;
        std::string msg = "GAME OVER";
        float x = resolution.x / 2.0f - 180.0f;
        float y = resolution.y / 2.0f - 60;
        glm::vec3 color = glm::vec3(1, 0, 0);

        text_renderer->RenderText(msg, x, y, text_scale, color);
        return;
    }

    if (count_stricate >= 4 || lifes_express <= 0) {
        if (!is_ending) {
            is_ending = true;
            game_over_timer = 1.0f;
        }
    }

    if (is_ending) {
        game_over_timer -= delta_time;
        if (game_over_timer <= 0.0f) {
            game_over = true;
        }
    }
    else {
        if (window->KeyHold(GLFW_KEY_F)) {
            for (auto& track : track_segments) {
                if (track.is_broken) {
                    glm::vec3 track_pos = glm::vec3(track.model_matrix[3]);
                    if (glm::distance(drezina_pos, track_pos) < 2.0f) {
                        track.is_broken = false;
                        count_stricate--;
                        if (count_stricate < 0) count_stricate = 0;
                    }
                }
            }
        }

        Update_broken_tracks(delta_time);
        Update_train_pos(delta_time);
        Update_express_pos(delta_time);

        if (tps_camera) {
            float dist_behind = 6.0f;
            float dist_up = 3.0f;
            float correct_angle = drezina_rot - 1.5708f * 2;
            glm::vec3 target_pos = drezina_pos + glm::vec3(0, dist_up, 0);
            glm::vec3 cam_pos = drezina_pos + glm::vec3(-sin(correct_angle) * dist_behind, dist_up, -cos(correct_angle) * dist_behind);
            camera->Set(cam_pos, target_pos, glm::vec3(0, 1, 0));
        }

        total_time += delta_time;
    }

    Render_terrain();
    Render_tracks();
    Render_stations();
    Render_train();
    Render_express();
    Render_drezina();

    glm::ivec2 resolution = window->GetResolution();
    glm::vec3 text_color = glm::vec3(1.0f, 1.0f, 1.0f);
    float text_scale = 0.75f;

    std::string time_str = "Time: " + std::to_string((int)total_time);
    text_renderer->RenderText(time_str, 5.0f, 40.0f, text_scale, text_color);

    std::string broken_str = "Broken: " + std::to_string(count_stricate) + "/4";
    glm::vec3 status_color = (count_stricate >= 3) ? glm::vec3(1.0f, 0.0f, 0.0f) : glm::vec3(1.0f, 1.0f, 1.0f);
    text_renderer->RenderText(broken_str, 5.0f, 100.0f, text_scale, status_color);

    std::string lives_str = "LIFES EXPRESS TRAIN: " + std::to_string(lifes_express);
    glm::vec3 lives_color = (lifes_express == 0) ? glm::vec3(1.0f, 0.0f, 0.0f) : glm::vec3(1.0f, 1.0f, 1.0f);
    text_renderer->RenderText(lives_str, 5.0f, 160.0f, 0.75f, lives_color);
}

//update sine stricate
void Tema2::Update_broken_tracks(float delta_time)
{
    time_until_break -= delta_time;

    if (time_until_break <= 0.0f) {
        time_until_break = 2.0f + (rand() % 300) / 100.0f;

        if (!track_segments.empty()) {
            int attempts = 0;
            while (attempts < 10) {
                int idx = rand() % track_segments.size();

                if (!track_segments[idx].is_broken) {
                    track_segments[idx].is_broken = true;
                    count_stricate++;
                    break;
                }
                attempts++;
            }
        }
    }
}

//update tren pozitie
void Tema2::Update_train_pos(float delta_time)
{
    if (rail_path.empty()) return;

    if (is_station_stopped) {
        station_stop_timer -= delta_time;
        if (station_stop_timer <= 0.0f) {
            is_station_stopped = false;
        }
        else {
            return;
        }
    }

    for (int i = 0; i < station_pos.size(); i++) {
        float dist_to_station = glm::distance(train_pos, station_pos[i]);

        if (dist_to_station < 2.5f && i != last_station_idx) {
            bool should_stop = (rand() % 100) < 50;

            if (should_stop) {
                is_station_stopped = true;
                station_stop_timer = 2.0f + (rand() % 100) / 100.0f;
                last_station_idx = i;
                return;
            }
            else {
                last_station_idx = i;
            }
        }
    }

    if (last_station_idx != -1) {
        float dist_to_last = glm::distance(train_pos, station_pos[last_station_idx]);
        if (dist_to_last > 4.0f) {
            last_station_idx = -1;
        }
    }

    bool emergency_stop = false;
    for (const auto& track : track_segments) {
        if (track.is_broken && glm::distance(train_pos, glm::vec3(track.model_matrix[3])) < 2.0f) {
            emergency_stop = true;
            break;
        }
    }
    if (emergency_stop) return;

    train_prog += delta_time * train_speed;
    if (train_prog >= 1.0f) {
        train_prog = 0.0f;
        cur_seg = (cur_seg + 1) % rail_path.size();
    }
    Rail_segment& seg = rail_path[cur_seg];
    train_pos = glm::mix(seg.start_pos, seg.end_pos, train_prog);
    glm::vec3 dir = glm::normalize(seg.end_pos - seg.start_pos);
    train_rot = atan2(dir.x, dir.z) + glm::pi<float>() / 2.0f;
}

//update express pozitie
void Tema2::Update_express_pos(float delta_time)
{
    if (rail_path.empty()) return;

    if (express_stop) {
        express_timer -= delta_time;
        if (express_timer <= 0.0f)
            express_stop = false;
        else
            return;
    }

    if (glm::distance(express_pos, train_pos) < 5.0f) {
        express_stop = true;
        express_timer = 4.0f;
        return;
    }

    for (const auto& track : track_segments) {
        if (track.is_broken && glm::distance(express_pos, glm::vec3(track.model_matrix[3])) < 2.0f) {
            if (!is_ending && lifes_express > 0)
                lifes_express = 0;
            return;
        }
    }

    express_prog += delta_time * express_speed;
    if (express_prog >= 1.0f) {
        express_prog = 0.0f;
        express_seg = (express_seg + 1) % rail_path.size();
    }
    Rail_segment& seg = rail_path[express_seg];
    express_pos = glm::mix(seg.start_pos, seg.end_pos, express_prog);
    glm::vec3 dir = glm::normalize(seg.end_pos - seg.start_pos);
    express_rot = atan2(dir.x, dir.z) + glm::pi<float>() / 2.0f;
}

void Tema2::Render_cell(Mesh* mesh, Shader* shader, const glm::mat4& model_matrix, const glm::vec3& color)
{
    if (!mesh || !shader || !shader->GetProgramID())
        return;

    shader->Use();

    GLint loc_model = glGetUniformLocation(shader->program, "Model");
    glUniformMatrix4fv(loc_model, 1, GL_FALSE, glm::value_ptr(model_matrix));

    GLint loc_view = glGetUniformLocation(shader->program, "View");
    glUniformMatrix4fv(loc_view, 1, GL_FALSE, glm::value_ptr(camera->GetViewMatrix()));

    GLint loc_proj = glGetUniformLocation(shader->program, "Projection");
    glUniformMatrix4fv(loc_proj, 1, GL_FALSE, glm::value_ptr(projectionMatrix));

    GLint loc_color = glGetUniformLocation(shader->program, "color");
    glUniform3fv(loc_color, 1, glm::value_ptr(color));

    mesh->Render();
}

void Tema2::Render_terrain()
{
    if (terrain_map.empty()) return;

    Shader* shader = shaders["TerrainShader"];
    Mesh* quad = meshes["quad"];

    float ter_w = map_w * cell_size;
    float ter_h = map_h * cell_size;

    for (int x = 0; x < map_w; ++x) {
        for (int z = 0; z < map_h; ++z) {
            glm::vec3 color;

            if (terrain_map[x][z] == WATER) {
                color = glm::vec3(0.2f, 0.5f, 0.9f);
            }
            else if (terrain_map[x][z] == MOUNTAIN) {
                color = glm::vec3(0.6f, 0.4f, 0.2f);
            }
            else {
                color = glm::vec3(0.3f, 0.8f, 0.2f);
            }
            glm::mat4 model = glm::mat4(1);
            model = glm::translate(model, glm::vec3((float)x * cell_size - ter_w / 2.0f, 0.0f, (float)z * cell_size - ter_h / 2.0f));
            model = glm::scale(model, glm::vec3(cell_size, 1.0f, cell_size));

            Render_cell(quad, shader, model, color);
        }
    }
}

void Tema2::Render_tracks()
{
    Shader* shader = shaders["TerrainShader"];
    Mesh* track_mesh = meshes["track"];

    if (!shader || !track_mesh) return;

    for (const auto& segment : track_segments) {
        glUseProgram(shader->program);
        GLint loc_broken = glGetUniformLocation(shader->program, "is_broken");
        glUniform1i(loc_broken, segment.is_broken ? 1 : 0);

        if (segment.is_broken) {
            glm::vec3 color = glm::vec3(0.0f, 0.0f, 0.0f);
            glm::mat4 broken_model = segment.model_matrix;
            broken_model = glm::translate(broken_model, glm::vec3(0.0f, 0.4f, 0.0f));
            broken_model = glm::rotate(broken_model, RADIANS(10.0f), glm::vec3(0, 1, 0));
            Render_cell(track_mesh, shader, broken_model, color);
        }
        else {
            Render_cell(track_mesh, shader, segment.model_matrix, segment.color);
        }
    }
}

void Tema2::Render_stations()
{
    Shader* shader = shaders["TerrainShader"];
    float ter_w = map_w * cell_size;
    float ter_h = map_h * cell_size;
    float pos_x, pos_z;
    glm::mat4 model;

    pos_x = (float)2 * cell_size - ter_w / 2.0f;
    pos_z = (float)0 * cell_size - ter_h / 2.0f;
    model = glm::mat4(1);
    model = glm::translate(model, glm::vec3(pos_x, 0, pos_z));
    model = glm::scale(model, glm::vec3(1.2f, 3.0f, 1.2f));
    Render_cell(meshes["box"], shader, model, glm::vec3(1.0f, 0.0f, 0.0f));


    pos_x = (float)3 * cell_size - ter_w / 2.0f + 1;
    pos_z = (float)7 * cell_size - ter_h / 2.0f + 0.8;
    model = glm::mat4(1);
    model = glm::translate(model, glm::vec3(pos_x, 0, pos_z));
    model = glm::scale(model, glm::vec3(1.8f, 3.5f, 1.8f));
    Render_cell(meshes["cylinder"], shader, model, glm::vec3(0.0f, 0.0f, 0.5f));


    pos_x = (float)7 * cell_size - ter_w / 2.0f + 2.3;
    pos_z = (float)3 * cell_size - ter_h / 2.0f;
    model = glm::mat4(1);
    model = glm::translate(model, glm::vec3(pos_x, 0, pos_z));
    model = glm::scale(model, glm::vec3(1.5f, 4.0f, 1.5f));
    Render_cell(meshes["pyramid"], shader, model, glm::vec3(1.0f, 0.65f, 0.0f));

}

void Tema2::Render_train()
{
    Shader* shader = shaders["TerrainShader"];
    float base_x = train_pos.x;
    float base_z = train_pos.z;
    float wheel_r = 0.3f;
    float wheel_y = 0.05f;

    glm::mat4 base_model = glm::mat4(1);
    base_model = glm::translate(base_model, glm::vec3(base_x, 0, base_z));
    base_model = glm::rotate(base_model, train_rot, glm::vec3(0, 1, 0));
    glm::mat4 model;

    model = base_model;
    model = glm::translate(model, glm::vec3(-0.9f, wheel_y, -0.35f));
    model = glm::scale(model, glm::vec3(wheel_r, wheel_r, 0.8f));
    Render_cell(meshes["cylinder"], shader, model, glm::vec3(1.0f, 0.0f, 0.0f));


    model = base_model;
    model = glm::translate(model, glm::vec3(-0.9f, wheel_y, 0.35f));
    model = glm::scale(model, glm::vec3(wheel_r, wheel_r, 0.8f));
    Render_cell(meshes["cylinder"], shader, model, glm::vec3(1.0f, 0.0f, 0.0f));


    model = base_model;
    model = glm::translate(model, glm::vec3(-0.15f, wheel_y, -0.35f));
    model = glm::scale(model, glm::vec3(wheel_r, wheel_r, 0.8f));
    Render_cell(meshes["cylinder"], shader, model, glm::vec3(1.0f, 0.0f, 0.0f));


    model = base_model;
    model = glm::translate(model, glm::vec3(-0.15f, wheel_y, 0.35f));
    model = glm::scale(model, glm::vec3(wheel_r, wheel_r, 0.8f));
    Render_cell(meshes["cylinder"], shader, model, glm::vec3(1.0f, 0.0f, 0.0f));


    model = base_model;
    model = glm::translate(model, glm::vec3(0.6f, wheel_y, -0.35f));
    model = glm::scale(model, glm::vec3(wheel_r, wheel_r, 0.8f));
    Render_cell(meshes["cylinder"], shader, model, glm::vec3(1.0f, 0.0f, 0.0f));


    model = base_model;
    model = glm::translate(model, glm::vec3(0.6f, wheel_y, 0.35f));
    model = glm::scale(model, glm::vec3(wheel_r, wheel_r, 0.8f));
    Render_cell(meshes["cylinder"], shader, model, glm::vec3(1.0f, 0.0f, 0.0f));


    model = base_model;
    model = glm::translate(model, glm::vec3(-0.15f, 0.35f, 0.0f));
    model = glm::scale(model, glm::vec3(2.2f, 0.15f, 0.75f));
    Render_cell(meshes["box"], shader, model, glm::vec3(1.0f, 1.0f, 0.0f));


    model = base_model;
    model = glm::translate(model, glm::vec3(-0.2f, 0.75f, 0.0f));
    model = glm::rotate(model, RADIANS(90.0f), glm::vec3(0, 0, 1));
    model = glm::scale(model, glm::vec3(1.1f, 0.75f, 1.5f));
    Render_cell(meshes["cylinder"], shader, model, glm::vec3(0.0f, 0.0f, 1.0f));


    model = base_model;
    model = glm::translate(model, glm::vec3(0.35f, 0.5f, 0.0f));
    model = glm::scale(model, glm::vec3(1.0f, 0.9f, 0.7f));
    Render_cell(meshes["box"], shader, model, glm::vec3(0.0f, 1.0f, 0.0f));


    model = base_model;
    model = glm::translate(model, glm::vec3(1.7f, wheel_y, -0.35f));
    model = glm::scale(model, glm::vec3(wheel_r, wheel_r, 0.8f));
    Render_cell(meshes["cylinder"], shader, model, glm::vec3(1.0f, 0.0f, 0.0f));


    model = base_model;
    model = glm::translate(model, glm::vec3(1.7f, wheel_y, 0.35f));
    model = glm::scale(model, glm::vec3(wheel_r, wheel_r, 0.8f));
    Render_cell(meshes["cylinder"], shader, model, glm::vec3(1.0f, 0.0f, 0.0f));


    model = base_model;
    model = glm::translate(model, glm::vec3(3.2f, wheel_y, -0.35f));
    model = glm::scale(model, glm::vec3(wheel_r, wheel_r, 0.8f));
    Render_cell(meshes["cylinder"], shader, model, glm::vec3(1.0f, 0.0f, 0.0f));


    model = base_model;
    model = glm::translate(model, glm::vec3(3.2f, wheel_y, 0.35f));
    model = glm::scale(model, glm::vec3(wheel_r, wheel_r, 0.8f));
    Render_cell(meshes["cylinder"], shader, model, glm::vec3(1.0f, 0.0f, 0.0f));


    model = base_model;
    model = glm::translate(model, glm::vec3(2.45f, 0.35f, 0.0f));
    model = glm::scale(model, glm::vec3(2.2f, 0.15f, 0.75f));
    Render_cell(meshes["box"], shader, model, glm::vec3(1.0f, 1.0f, 0.0f));


    model = base_model;
    model = glm::translate(model, glm::vec3(2.5f, 0.5f, 0.0f));
    model = glm::scale(model, glm::vec3(2.0f, 0.9f, 0.7f));
    Render_cell(meshes["box"], shader, model, glm::vec3(0.0f, 1.0f, 0.0f));

}

void Tema2::Render_express()
{
    Shader* shader = shaders["TerrainShader"];
    float base_x = express_pos.x;
    float base_z = express_pos.z;
    float wheel_r = 0.3f;
    float wheel_y = 0.05f;

    glm::mat4 base_model = glm::mat4(1);
    base_model = glm::translate(base_model, glm::vec3(base_x, 0, base_z));
    base_model = glm::rotate(base_model, express_rot, glm::vec3(0, 1, 0));
    glm::mat4 model;


    model = base_model;
    model = glm::translate(model, glm::vec3(-0.9f, wheel_y, -0.35f));
    model = glm::scale(model, glm::vec3(wheel_r, wheel_r, 0.8f));
    Render_cell(meshes["cylinder"], shader, model, glm::vec3(1.0f, 0.0f, 0.0f));


    model = base_model;
    model = glm::translate(model, glm::vec3(-0.9f, wheel_y, 0.35f));
    model = glm::scale(model, glm::vec3(wheel_r, wheel_r, 0.8f));
    Render_cell(meshes["cylinder"], shader, model, glm::vec3(1.0f, 0.0f, 0.0f));


    model = base_model;
    model = glm::translate(model, glm::vec3(-0.15f, wheel_y, -0.35f));
    model = glm::scale(model, glm::vec3(wheel_r, wheel_r, 0.8f));
    Render_cell(meshes["cylinder"], shader, model, glm::vec3(1.0f, 0.0f, 0.0f));


    model = base_model;
    model = glm::translate(model, glm::vec3(-0.15f, wheel_y, 0.35f));
    model = glm::scale(model, glm::vec3(wheel_r, wheel_r, 0.8f));
    Render_cell(meshes["cylinder"], shader, model, glm::vec3(1.0f, 0.0f, 0.0f));


    model = base_model;
    model = glm::translate(model, glm::vec3(0.6f, wheel_y, -0.35f));
    model = glm::scale(model, glm::vec3(wheel_r, wheel_r, 0.8f));
    Render_cell(meshes["cylinder"], shader, model, glm::vec3(1.0f, 0.0f, 0.0f));


    model = base_model;
    model = glm::translate(model, glm::vec3(0.6f, wheel_y, 0.35f));
    model = glm::scale(model, glm::vec3(wheel_r, wheel_r, 0.8f));
    Render_cell(meshes["cylinder"], shader, model, glm::vec3(1.0f, 0.0f, 0.0f));


    model = base_model;
    model = glm::translate(model, glm::vec3(-0.15f, 0.35f, 0.0f));
    model = glm::scale(model, glm::vec3(2.2f, 0.15f, 0.75f));
    Render_cell(meshes["box"], shader, model, glm::vec3(1.0f, 0.84f, 0.0f));


    model = base_model;
    model = glm::translate(model, glm::vec3(-0.2f, 0.75f, 0.0f));
    model = glm::rotate(model, RADIANS(90.0f), glm::vec3(0, 0, 1));
    model = glm::scale(model, glm::vec3(1.1f, 0.75f, 1.5f));
    Render_cell(meshes["cylinder"], shader, model, glm::vec3(0.0f, 0.0f, 0.0f));


    model = base_model;
    model = glm::translate(model, glm::vec3(0.35f, 0.5f, 0.0f));
    model = glm::scale(model, glm::vec3(1.0f, 0.9f, 0.7f));
    Render_cell(meshes["box"], shader, model, glm::vec3(1.0f, 0.84f, 0.0f));


    model = base_model;
    model = glm::translate(model, glm::vec3(1.7f, wheel_y, -0.35f));
    model = glm::scale(model, glm::vec3(wheel_r, wheel_r, 0.8f));
    Render_cell(meshes["cylinder"], shader, model, glm::vec3(1.0f, 0.0f, 0.0f));


    model = base_model;
    model = glm::translate(model, glm::vec3(1.7f, wheel_y, 0.35f));
    model = glm::scale(model, glm::vec3(wheel_r, wheel_r, 0.8f));
    Render_cell(meshes["cylinder"], shader, model, glm::vec3(1.0f, 0.0f, 0.0f));


    model = base_model;
    model = glm::translate(model, glm::vec3(3.2f, wheel_y, -0.35f));
    model = glm::scale(model, glm::vec3(wheel_r, wheel_r, 0.8f));
    Render_cell(meshes["cylinder"], shader, model, glm::vec3(1.0f, 0.0f, 0.0f));


    model = base_model;
    model = glm::translate(model, glm::vec3(3.2f, wheel_y, 0.35f));
    model = glm::scale(model, glm::vec3(wheel_r, wheel_r, 0.8f));
    Render_cell(meshes["cylinder"], shader, model, glm::vec3(1.0f, 0.0f, 0.0f));


    model = base_model;
    model = glm::translate(model, glm::vec3(2.45f, 0.35f, 0.0f));
    model = glm::scale(model, glm::vec3(2.2f, 0.15f, 0.75f));
    Render_cell(meshes["box"], shader, model, glm::vec3(1.0f, 0.84f, 0.0f));


    model = base_model;
    model = glm::translate(model, glm::vec3(2.5f, 0.5f, 0.0f));
    model = glm::scale(model, glm::vec3(2.0f, 0.9f, 0.7f));
    Render_cell(meshes["box"], shader, model, glm::vec3(1.0f, 0.84f, 0.0f));

}

void Tema2::Render_drezina()
{
    Shader* shader = shaders["TerrainShader"];
    float base_x = drezina_pos.x;
    float base_y = drezina_pos.y;
    float base_z = drezina_pos.z;

    float wheel_r = 0.25f;
    float wheel_w = 0.8f;

    glm::vec3 color_orange = glm::vec3(0.9f, 0.6f, 0.2f);
    glm::vec3 color_grey = glm::vec3(0.3f, 0.3f, 0.3f);
    glm::vec3 color_green = glm::vec3(0.1f, 0.9f, 0.1f);

    float wheel_off_x = 0.45f;
    float wheel_off_z = 0.35f;

    glm::mat4 base_model = glm::mat4(1);
    base_model = glm::translate(base_model, glm::vec3(base_x, base_y, base_z));
    base_model = glm::rotate(base_model, drezina_rot, glm::vec3(0, 1, 0));
    glm::mat4 model;


    model = base_model;
    model = glm::translate(model, glm::vec3(-wheel_off_x, 0, -wheel_off_z));
    model = glm::scale(model, glm::vec3(wheel_r, wheel_r, wheel_w));
    Render_cell(meshes["cylinder"], shader, model, color_grey);

    model = base_model;
    model = glm::translate(model, glm::vec3(wheel_off_x, 0, -wheel_off_z));
    model = glm::scale(model, glm::vec3(wheel_r, wheel_r, wheel_w));
    Render_cell(meshes["cylinder"], shader, model, color_grey);

    model = base_model;
    model = glm::translate(model, glm::vec3(-wheel_off_x, 0, wheel_off_z));
    model = glm::scale(model, glm::vec3(wheel_r, wheel_r, wheel_w));
    Render_cell(meshes["cylinder"], shader, model, color_grey);

    model = base_model;
    model = glm::translate(model, glm::vec3(wheel_off_x, 0, wheel_off_z));
    model = glm::scale(model, glm::vec3(wheel_r, wheel_r, wheel_w));
    Render_cell(meshes["cylinder"], shader, model, color_grey);


    model = base_model;
    model = glm::translate(model, glm::vec3(0.0f, 0.25f, 0.0f));
    model = glm::scale(model, glm::vec3(1.1f, 0.2f, 0.9f));
    Render_cell(meshes["box"], shader, model, color_orange);


    model = base_model;
    model = glm::translate(model, glm::vec3(0.0f, 0.5f, 0.0f));
    model = glm::scale(model, glm::vec3(0.2f, 0.6f, 0.2f));
    Render_cell(meshes["box"], shader, model, color_orange);

    float current_rocking = sin(handle_angle) * 0.5f;

    glm::mat4 pivot_matrix = base_model;
    pivot_matrix = glm::translate(pivot_matrix, glm::vec3(0.0f, 0.9f, 0.0f));
    pivot_matrix = glm::rotate(pivot_matrix, current_rocking, glm::vec3(1, 0, 0));
    pivot_matrix = glm::translate(pivot_matrix, glm::vec3(0.0f, -0.9f, 0.0f));


    model = pivot_matrix;
    model = glm::translate(model, glm::vec3(0.0f, 1.15f, -0.4f));
    model = glm::rotate(model, RADIANS(90.0f), glm::vec3(1, 0, 0));
    model = glm::scale(model, glm::vec3(0.2f, 0.8f, 0.2f));
    Render_cell(meshes["cylinder"], shader, model, color_grey);


    model = pivot_matrix;
    model = glm::translate(model, glm::vec3(0.0f, 1.0f, -0.4f));
    model = glm::scale(model, glm::vec3(0.2f, 0.25f, 0.2f));
    Render_cell(meshes["cylinder"], shader, model, color_green);


    model = pivot_matrix;
    model = glm::translate(model, glm::vec3(0.0f, 1.0f, 0.4f));
    model = glm::scale(model, glm::vec3(0.2f, 0.25f, 0.2f));
    Render_cell(meshes["cylinder"], shader, model, color_green);

}

void Tema2::FrameEnd()
{
}

void Tema2::OnInputUpdate(float delta_time, int mods)
{
    float cam_speed_local = 14.0f * delta_time;
    if (window->KeyHold(GLFW_KEY_W)) camera->TranslateForward(cam_speed_local);
    if (window->KeyHold(GLFW_KEY_S)) camera->TranslateForward(-cam_speed_local);
    if (window->KeyHold(GLFW_KEY_A)) camera->TranslateRight(-cam_speed_local);
    if (window->KeyHold(GLFW_KEY_D)) camera->TranslateRight(cam_speed_local);
    if (window->KeyHold(GLFW_KEY_Q)) camera->TranslateUpward(-cam_speed_local);
    if (window->KeyHold(GLFW_KEY_E)) camera->TranslateUpward(cam_speed_local);

    if (rail_path.empty()) return;

    float dir = 0.0f;

    if (window->KeyHold(GLFW_KEY_UP)) dir = 1.0f;
    if (window->KeyHold(GLFW_KEY_DOWN)) dir = -1.0f;

    if (dir != 0.0f) {
        Rail_segment& cur_seg = rail_path[drezina_seg_idx];
        float dist = glm::distance(cur_seg.start_pos, cur_seg.end_pos);

        drezina_t += (dir * drezina_speed * delta_time) / dist;

        handle_angle += delta_time * 15.0f;
    }
    else {
        handle_angle = glm::mix(handle_angle, 0.0f, delta_time * 5.0f);
    }

    if (drezina_t >= 1.0f) {
        drezina_t = 0.0f;
        drezina_seg_idx++;
        if (drezina_seg_idx >= rail_path.size()) {
            drezina_seg_idx = 0;
        }
    }
    else if (drezina_t < 0.0f) {
        drezina_t = 1.0f;
        drezina_seg_idx--;
        if (drezina_seg_idx < 0) {
            drezina_seg_idx = rail_path.size() - 1;
        }
    }

    Rail_segment& seg = rail_path[drezina_seg_idx];
    drezina_pos = glm::mix(seg.start_pos, seg.end_pos, drezina_t);

    glm::vec3 direction = glm::normalize(seg.end_pos - seg.start_pos);
    drezina_rot = atan2(direction.x, direction.z) + glm::pi<float>() / 2.0f;
}

void Tema2::OnMouseMove(int mouse_x, int mouse_y, int delta_x, int delta_y)
{
    if (!tps_camera && window->MouseHold(GLFW_MOUSE_BUTTON_RIGHT)) {
        float sensitivity = 0.001f;

        if (window->GetSpecialKeyState() == 0) {
            camera->RotateFirstPerson_OY(-delta_x * sensitivity);
            camera->RotateFirstPerson_OX(-delta_y * sensitivity);
        }

        if (window->GetSpecialKeyState() & GLFW_MOD_CONTROL) {
            camera->RotateThirdPerson_OY(-delta_x * sensitivity);
            camera->RotateThirdPerson_OX(-delta_y * sensitivity);
        }
    }
}
void Tema2::OnMouseBtnPress(int mouse_x, int mouse_y, int button, int mods)
{
}

void Tema2::OnMouseBtnRelease(int mouse_x, int mouse_y, int button, int mods)
{
}

void Tema2::OnKeyPress(int key, int mods)
{
    if (key == GLFW_KEY_G) {
        tps_camera = !tps_camera;
    }
}

void Tema2::OnKeyRelease(int key, int mods)
{
}

void Tema2::OnMouseScroll(int mouse_x, int mouse_y, int offset_x, int offset_y)
{
}

void Tema2::OnWindowResize(int width, int height)
{
}