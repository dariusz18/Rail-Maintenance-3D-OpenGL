#pragma once
#include <vector>
#include "components/simple_scene.h"
#include "components/text_renderer.h"
#include "lab_m1/lab5/lab_camera.h"

namespace m1
{
    struct Rail_segment {
        glm::vec3 start_pos;
        glm::vec3 end_pos;
    };

    struct Visual_track_segment {
        glm::mat4 model_matrix;
        bool is_broken;
        glm::vec3 color;
    };

    class Tema2 : public gfxc::SimpleScene
    {
    public:
        Tema2();
        ~Tema2();
        void Init() override;
        Mesh* Create_mesh(const char* name, const std::vector<VertexFormat>& vertices, const std::vector<unsigned int>& indices);

    private:
        void FrameStart() override;
        void Update(float delta_time) override;
        void FrameEnd() override;

        void OnInputUpdate(float delta_time, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouse_x, int mouse_y, int delta_x, int delta_y) override;
        void OnMouseBtnPress(int mouse_x, int mouse_y, int button, int mods) override;
        void OnMouseBtnRelease(int mouse_x, int mouse_y, int button, int mods) override;
        void OnMouseScroll(int mouse_x, int mouse_y, int offset_x, int offset_y) override;
        void OnWindowResize(int width, int height) override;

        void Generate_terrain(int w, int h);
        void Init_rail_path();
        void Generate_track_segments();

        void Update_train_pos(float delta_time);
        void Update_express_pos(float delta_time);
        void Update_broken_tracks(float delta_time);

        void Render_cell(Mesh* mesh, Shader* shader, const glm::mat4& model_matrix, const glm::vec3& color);
        void Render_terrain();
        void Render_tracks();
        void Render_stations();
        void Render_train();
        void Render_express();
        void Render_drezina();

        enum Terrain_type { PLAIN = 0, WATER = 1, MOUNTAIN = 2 };
        std::vector<std::vector<Terrain_type>> terrain_map;
        int map_w;
        int map_h;
        float cell_size;

        std::vector<Rail_segment> rail_path;
        std::vector<Visual_track_segment> track_segments;
        std::vector<glm::vec3> station_pos;

        int cur_seg;
        float train_prog;
        float train_speed;
        glm::vec3 train_pos;
        float train_rot;

        int express_seg;
        float express_prog;
        float express_speed;
        glm::vec3 express_pos;
        float express_rot;

        int drezina_seg_idx;
        float drezina_t;
        float drezina_speed;
        float handle_angle;
        glm::vec3 drezina_pos;
        float drezina_rot;

        bool tps_camera;
        bool is_station_stopped;
        float station_stop_timer;
        int last_station_idx;

        float time_until_break;
        int count_stricate;
        bool game_over;

        int lifes_express;

        float total_time;

        bool is_ending;
        float game_over_timer;

        bool express_stop;
        float express_timer;

        gfxc::TextRenderer* text_renderer;

        implemented::Camera* camera;
        glm::mat4 projectionMatrix;
        float fov;
        float zNear, zFar;
    };
}