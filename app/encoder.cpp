#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <unordered_map>
#include <string>
#include <vector>

namespace py = pybind11;

class Encoder {
public:
    Encoder() = default;

    std::vector<int> encode(const std::string& text) {
        std::unordered_map<char, int> char_to_index;
        int current_index = 0;

        std::vector<int> encoded_text;
        for (char ch : text) {
            if (char_to_index.find(ch) == char_to_index.end()) {
                char_to_index[ch] = current_index++;
            }
            encoded_text.push_back(char_to_index[ch]);
        }
        return encoded_text;
    }

    std::string decode(const std::vector<int>& encoded_text) {
        std::unordered_map<int, char> index_to_char;
        int current_index = 0;

        // Generate index_to_char map
        for (const auto& pair : encoded_text) {
            if (index_to_char.find(pair) == index_to_char.end()) {
                index_to_char[pair] = current_index++;
            }
        }

        std::string decoded_text;
        for (int index : encoded_text) {
            decoded_text += index_to_char[index];
        }
        return decoded_text;
    }
};

PYBIND11_MODULE(encoder, m) {
    py::class_<Encoder>(m, "Encoder")
        .def(py::init<>())
        .def("encode", &Encoder::encode, "Encode a text to numeric representation")
        .def("decode", &Encoder::decode, "Decode numeric representation to text");
}
