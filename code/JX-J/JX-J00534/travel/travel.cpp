#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2){
        cout << 1;
        int a = (s1[0] - '0') * 10 + (s1[1] - '0'),b = (s2[0] - '0') * 10 + (s2[1] - '0');
        if(a == b){
                cout << 1;
            int c = s1[2] - 'A' + 1,d = s2[2] - 'A' + 1;
            if(s1[2] == 'F') {c--;}
            if(s2[2] == 'F') {d--;}
            if((c <= 3 && d <= 3) || (c >= 4 && d >= 4)){
                cout << 1;
                if(c - d == 1 || c - d == -1){
                    cout << 1;
                }else{
                    cout << 0;
                }
            }else{
                cout << 0 << 0;
            }
        }else{
            cout << 0 << 0 << 0;
        }
    }else{
        cout << 0 << 0 << 0 << 0;
    }


    return 0;
}
