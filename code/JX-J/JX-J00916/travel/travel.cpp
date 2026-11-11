#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1==c2) cout << 1;
    else cout << 0;
    int cmp=0;
    for(int i=0;i<2;i++){
        if(s1[i]==s2[i]){
            cmp++;
            if(cmp==2) cout << 1;
        }
    }
    if(cmp!=2) cout << 0;
    if(s1[2]==s2[2]) cout << 1 << 1;
    else if((s1[2]!="D"||s1[2]!="E")&&(s2[2]!="D"||s2[2]!="E")) cout << 1 << 0;
    else if((s1[2]=="D"||s1[2]=="E")&&(s2[2]=="D"||s2[2]=="E")) cout << 1 << 1;
    else cout << 0 << 0;
    return 0;
}
