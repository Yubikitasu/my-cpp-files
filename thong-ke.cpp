#include <bits/stdc++.h>

using namespace std;


int main() {
    vector<pair<float, float>> v;
    int n;
    float m;
    float xtb;
    float s2;
    cin >> n;
    for (int i = 0; i < n; i++) {
        float a, x, y, b; cin >> x >> y >> b;
        a = (x+y)/2;
        m += b;
        v.push_back({a, b});
    }
    for (int j = 0; j < n; j++) {
        pair<float, float> x = v[j];
        xtb += (x.first * x.second * (1/m));
    }
    for (int k = 0; k < n; k++) {
        pair<float, float> x = v[k];
        s2 += (x.second * pow((x.first - xtb), 2) * (1/m));
    }
    
    cout << "x trung binh: " << xtb << endl;
    cout << "Phuong sai: " << s2 << endl;
    cout << "Do lech chuan: " << sqrt(s2) << endl;
    
    return 0;
}
