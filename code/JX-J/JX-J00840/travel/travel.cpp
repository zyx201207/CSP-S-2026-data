#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a1=0,a2=0,a3=0,a4=0;
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        a1=1;
    }
    if(a1==1&&s1[0]==s2[0]&&s1[1]==s2[1]){
        a2=1;
    }
    if(a2==1&&(s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
        a3=1;
    }
    if(a3==1&&(((s1[2]-s2[2]==1)||(s2[2]-s1[2]==1))||((s1[2]=='D'&&s2[2]=='F')||(s2[1]=='F'&&s2[2]=='D')))){
        a4=1;
    }
    cout<<a1<<a2<<a3<<a4;
    return 0;
}
