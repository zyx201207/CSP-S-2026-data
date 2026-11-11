#include<bits/stdc++.h>
using namespace std;
int a,c,jl,jl2;
string b,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a!=c)cout<<"0000";
    else{
        if(b[0]!=d[0]||b[1]!=d[1])cout<<"1000";
        else{
            if(b[2]=='A'||b[2]=='B'||b[2]=='C')jl=0;
            else jl=1;
            if(d[2]=='A'||d[2]=='B'||d[2]=='C')jl2=0;
            else jl2=1;
            if(jl!=jl2)cout<<"1100";
            else{
                if(b[2]>d[2])swap(b[2],d[2]);
                if(b[2]=='A'&&d[2]=='B')cout<<"1111";
                else if(b[2]=='B'&&d[2]=='C')cout<<"1111";
                else if(b[2]=='D'&&d[2]=='F')cout<<"1111";
                else cout<<"1110";
            }
        }
    }
    return 0;
}
