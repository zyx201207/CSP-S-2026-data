#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string c1,s1,c2,s2;
    int k1=0,k2=0,k3=0,k4=0;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        k1=1;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        k2=1;
    }
    if((s1[2]<'D'&&s2[2]<'D')||(s1[2]>'C'&&s2[2]>'C')){
        k3=1;
    }
    if(int(s1[2])+1==int(s2[2])||int(s1[2])==int(s2[2])+1){
        k4=1;
    }
    cout<<k1<<k2<<k3<<k4;
    return 0;
}
