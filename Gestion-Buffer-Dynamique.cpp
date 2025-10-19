#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

class Buffer {
private:
    size_t size;
    unsigned char* data;

public:
    Buffer() : size(0), data(nullptr) {
        cout << "[Création] Buffer par défaut (0 octet)" << endl;
    }

    Buffer(size_t n) : size(n) {
        data = new unsigned char[n];
        memset(data, 0, n);
        cout << "[Création] Buffer de " << size << " octet(s)" << endl;
    }

    Buffer(const Buffer& other) : size(other.size) {
        if (size > 0) {
            data = new unsigned char[size];
            memcpy(data, other.data, size);
        } else {
            data = nullptr;
        }
        cout << "[Copie] Buffer copié (" << size << " octet(s))" << endl;
    }

    Buffer& operator=(const Buffer& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            if (size > 0) {
                data = new unsigned char[size];
                memcpy(data, other.data, size);
            } else {
                data = nullptr;
            }
            cout << "[Affectation] Copie d’un buffer de " << size << " octet(s)" << endl;
        }
        return *this;
    }

    size_t getSize() const {
        return size;
    }

    void fill(unsigned char value) {
        if (data)
            memset(data, value, size);
    }

    void printHex() const {
        cout << "Buffer (" << size << " octet(s)) : ";
        for (size_t i = 0; i < size; ++i)
            cout << hex << uppercase << setw(2) << setfill('0') << static_cast<int>(data[i]) << " ";
        cout << dec << endl;
    }

    ~Buffer() {
        cout << "[Destruction] Buffer de " << size << " octet(s)" << " libéré." << endl;
        delete[] data;
    }
};

int main() {
    cout << "--- Début du programme ---" << endl;

    Buffer b1;
    Buffer b2(8);
    b2.fill(0xAA);
    Buffer b3 = b2;

    cout << "\n--- Affichage des buffers ---" << endl;
    cout << "b1 -> "; b1.printHex();
    cout << "b2 -> "; b2.printHex();
    cout << "b3 -> "; b3.printHex();

    cout << "\n--- Fin du programme ---" << endl;
    return 0;
}
