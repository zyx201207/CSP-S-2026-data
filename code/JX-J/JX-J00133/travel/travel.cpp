#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    int e[5] = {0,1,1,0,0};
    cin >> c1 >> s1 >> c2 >> s2;
    int c,d;
    if(c1 != c2){
        e[1] = 0;
        e[2] = 0;
        e[3] = 0;
    }
    else{
        int a = 0,b = 0;
        for(int i = 0;i <= s1.size() - 1;i++){
            if(s1[i] >= '0' && s1[i] <= '9') a = s1[i] - '0' + a * 10;
            if(s1[i] >= 'A' && s1[i] <= 'Z') c = s1[i] - 'A' + 1;
        }
        for(int i = 0;i <= s2.size() - 1;i++){
            if(s2[i] >= '0' && s2[i] <= '9') b = s2[i] - '0' + b * 10;
            if(s2[i] >= 'A' && s2[i] <= 'Z') d = s2[i] - 'A' + 1;
        }
        if(a != b){
            e[2] = 0;
            e[3] = 0;
        }
        else{
            if(((c == 1 || c == 2 || c == 3) && (d == 1 || d == 2 || d == 3)) || ((d == 4 || d == 5) && (c == 4 || c == 5))){
                e[3] = 1;
                if(abs(c - d) == 1 && (c != 3 && d != 4)) e[4] = 1;
                else e[4] = 0;
            }
            else{
                e[3] = 0;
                e[4] = 0;
            }
        }
    }
    for(int i = 1;i <= 4;i++){
        cout << e[i];
    }
    return 0;
}
