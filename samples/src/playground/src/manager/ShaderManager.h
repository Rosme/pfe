
#pragma once

#include "utils/Container.h"
#include "opengl/Program.h"
#include "opengl/Shader.h"
#include <GL/glew.h>
#include <vector>
#include <unordered_map>
#include <memory>

namespace pg {

class ShaderManager {
public:
    ShaderManager() = default;
    ~ShaderManager() = default;

    /**
     * @brief Add a shader stage into the compilation pipeline.
     * @param file The file containing the shader source code.
     * @param type The type of shader.
     *
     * Valid types are GL_COMPUTE_SHADER, GL_VERTEX_SHADER, GL_TESS_CONTROL_SHADER,
     * GL_TESS_EVALUATION_SHADER, GL_GEOMETRY_SHADER, GL_FRAGMENT_SHADER.
     */
    void        addShader(const std::string file, GLenum type);

    /**
     * @brief Compile the shaders currently in the pipeline to the given tag.
     * @param tag The tag with which you can get the shader
     */
    void        compile(const std::string& tag);

    /**
     * @brief Get the shader with the given tag.
     * @param tag
     */
    opengl::Program*    get(const std::string& tag) const;

    /**
     * @brief Delete all contained shaders.
     */
    void            clear();

private:
    Container<opengl::Program, 16>                    buffer_{};
    std::unordered_map<std::string, opengl::Program*> resources_{};
    std::vector<std::unique_ptr<opengl::Shader>>      shaderStages_{};

};

}

