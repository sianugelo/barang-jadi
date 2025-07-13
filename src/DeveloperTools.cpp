#include "ObjectExplorer.hpp"

#include "DeveloperTools.hpp"

DeveloperTools::DeveloperTools() {
    m_tools.push_back(std::make_shared<ObjectExplorer>());
}

void DeveloperTools::on_draw_ui() {
    if (!ImGui::CollapsingHeader(get_name().data())) {
        return;
    }

    for (auto& tool : m_tools) {
        tool->on_draw_ui();
    }

    ImGui::TreePop();
}

