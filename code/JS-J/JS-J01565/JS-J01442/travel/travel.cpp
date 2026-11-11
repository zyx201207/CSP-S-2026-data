#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2;
    int c1,c2;
    bool k1,k2,f1,f2,f3,f4;
    cin>>c1>>s1>>c2>>s2;
    f1=(c1==c2);
    f2=f1&&(s1[0]==s2[0])&&(s1[1]==s2[1]);
    f3=f2&&((s1[2]-'A'>2)==(s2[2]-'A'>2));
    f4=f3&&((s1[2]-s2[2]==1)||(s1[2]-s2[2]==-1));
    cout<<f1<<f2<<f3<<f4;
    return 0;
}
