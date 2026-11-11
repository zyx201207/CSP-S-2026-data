#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
int ssy[6];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    ssy[0]=ssy[1]=ssy[2]=1;
    ssy[3]=ssy[5]=2;

    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000\n";
        return 0;
    }
    cout<<1;
    if(!(s1[0]==s2[0] and s1[1]==s2[1])){
        cout<<"000\n";
        return 0;
    }
    cout<<1;

    int x1=ssy[s1[2]-'A'],x2=ssy[s2[2]-'A'];

    if(x1!=x2){
        cout<<"00\n";
        return 0;
    }
    cout<<1;
    if(abs(s1[2]-s2[2])==1 or (x1==2 and x2==2)) cout<<"1\n";
    else cout<<"0\n";

    return 0;
}
