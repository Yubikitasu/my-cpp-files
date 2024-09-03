#include <bits/stdc++.h>
#include <vector>

using namespace std;


int main() {
    vector<pair<float, float>> v;
    int n;
    float m;
    float xtb;
    float s2;
    cin >> n;
    for (int i = 0; i < n; i++) {
        float a, b; cin >> a >> b; // a: gia tri dai dien, b: gia tri tan so;
        m += b;
        v.push_back({a, b});
    }
    for (int j = 0; j < n; j++) {
        pair<float, float> x = v[j];
        xtb += (x.first * x.second * (1/m));
    }
    for (int k = 0; k < n; k++) {
        pair<float, float> x = v[k];
        s2 += (x.second * ((x.first - xtb) * (x.first - xtb)) * (1/m));
    }
    
    cout << "x trung binh: " << xtb << endl;
    cout << "Phuong sai: " << s2 << endl;
    cout << "Do lech chuan: " << sqrt(s2) << endl;
    
    return 0;
}
