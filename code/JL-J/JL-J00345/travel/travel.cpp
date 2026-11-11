#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int bo,bt;
    string c,a,cc,aa;
    cin >> c >> a >> cc >> aa;
    // 1
    if (c == cc)
    {
        cout << 1;
    }
    else{
        cout << 0;
    }
    // 2
    if (c == cc && a[0] == aa[0] && a[1] == aa[1]){
        cout <<1;
    }
    else{
        cout << 0;
    }
    // 3
    if (a[2] == 'A' || a[2] == 'B' || a[2] == 'C'){
      bo = 1;
    }
    else{
        bo = 0;
    }
    if (aa[2] == 'A' || aa[2] == 'B' || aa[2] == 'C'){
        bt = 1;
    }
    else{
        bt = 0;
    }
    if (c == cc && a[0] == aa[0] && a[1] == aa[1] && bo == bt){
        cout << 1;
    }
    else{
        cout << 0;
    }
    //4
    if (c == cc && a[0] == aa[0] && a[1] == aa[1] && bo == bt && a[2] - aa[2] == 1 || aa[2] - a[2] == 1){
        cout << 1;
    }
    else{
        cout << 0;
    }
    return 0;
}
