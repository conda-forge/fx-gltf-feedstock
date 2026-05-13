#include <cassert>
#include <sstream>

#include <fx/gltf.h>
#include <nlohmann/json.hpp>

int main() {
    std::stringstream input{
        R"({
            "asset": {"version": "2.0"},
            "scene": 0,
            "scenes": [{"nodes": [0]}],
            "nodes": [{"name": "root"}]
        })"};

    const fx::gltf::Document document = fx::gltf::LoadFromText(input, "");

    assert(document.asset.version == "2.0");
    assert(document.scene == 0);
    assert(document.nodes.size() == 1);
    assert(document.nodes.front().name == "root");

    const nlohmann::json roundtrip = document;
    assert(roundtrip.at("asset").at("version").get<std::string>() == "2.0");
    assert(roundtrip.at("nodes").at(0).at("name").get<std::string>() == "root");

    return 0;
}
