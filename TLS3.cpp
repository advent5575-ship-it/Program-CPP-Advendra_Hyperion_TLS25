#include <iostream>
#include <string>
using namespace std;

string warnaLampu(long t) {
    const int durasi[3] = {3, 80, 20};
    const string warna[3] = {"Kuning", "Merah", "Hijau"};
    const int total = 103;
    const int start = 45;

    int delta = (t - start) % total;
    if (delta < 0) delta += total;

    int batas[3] = {durasi[0], durasi[0] + durasi[1], total};

    int i = (delta < batas[0]) ? 0 :
            (delta < batas[1]) ? 1 : 2;

    return warna[i];
}

int main() {
    long detik[] = {80, 135, 150, 212};
    for (long t : detik) {
        cout << "Detik ke-" << t << " -> " << warnaLampu(t) << endl;
    }
    return 0;
}
