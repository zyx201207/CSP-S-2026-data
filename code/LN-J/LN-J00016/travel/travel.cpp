#include <bits/stdc++.h>
using namespace std;
char zuo[]={'A','B','C'},you[]={'D','E','*'};
bool findzuo(char x){
    for(int i=0;i<3;i++){
        if(zuo[i]==x) return true;
    }return false;
}
void init(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
}
int main(){
    init();
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1==c2) cout << 1;
    else cout << 0;
    if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]) cout << 1;
    else cout << 0;
    if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&findzuo(s1[2])==findzuo(s2[2])) cout << 1;
    else cout << 0;
    if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&findzuo(s1[2])==findzuo(s2[2])&&(s1[2]==s2[2]+1||s1[2]==s2[2]-1)) cout << 1;
    else cout << 0;
    return 0;
}
