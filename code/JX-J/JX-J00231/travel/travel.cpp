#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int p[6];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    for(int i = 0;i <= 2;i++)
        p[i] == 1;
    p[3] = 2;
    p[4] = 2;
    if(c1 == c2)
        cout << 1;
    else{
        cout << 0 << 0 << 0 << 0;
        return 0;
     }
    if(s1[0] == s2[0] && s1[1] == s2[1])
        cout << 1;
    else{
        cout << 0 << 0 << 0;
        return 0;
    }
    if(p[s1[2]-'A'] == p[s2[2] - 'A'])
        cout << 1;
    else{
        cout << 0 << 0;
        return 0;
    }
    if(s1[2] - s2[2] == 1 || s2[2] - s1[2] == 1)
        cout << 1;
    else
        cout << 0;
    return 0;
}


