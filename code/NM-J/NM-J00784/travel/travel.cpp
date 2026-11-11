#include<bits/stdc++.h>
using namespace std;
bool cmptr(string x,string y){
    bool ans=1;
    for(int i=0;i<x.length();i++){
        if(x[i]!=y[i])ans=0;
    }
    return ans;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(cmptr(c1,c2))cout << 1;
    else cout << 0;
    if(cmptr(c1,c2)&&s1[0]==s2[0]&&s1[1]==s2[1]) cout << 1;
    else cout << 0;
    if(cmptr(c1,c2)&&(s1[0]==s2[0]&&s1[1]==s2[1])&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))) cout << 1;
    else cout << 0;
    if(cmptr(c1,c2)&&(s1[0]==s2[0]&&s1[1]==s2[1])&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))&&(abs(s1[2]-s2[2])==1)) cout << 1;
    else cout << 0;
    return 0;
}