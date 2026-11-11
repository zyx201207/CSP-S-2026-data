#include <bits/stdc++.h>
using namespace std;
int a[200];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    a[s1[2]]=a[s2[2]]=1;
    if(c1!=c2){
        cout<<"0000";
    }
    else if(s1[0]!=s2[0]||s1[1]!=s2[1]){
        cout<<"1000";
    }
    else if(a['A']+a['B']+a['C']!=2&&a['D']+a['F']!=2){
        cout<<"1100";
    }
    else if(a['A']==a['B']||a['B']==a['C']||a['D']==a['F']){
        cout<<"1111";
    }
    else cout<<"1110";
    return 0;
}