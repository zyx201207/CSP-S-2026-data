#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    std::cin.tie(0);
    std::cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int xi=0,pa=0;
    string c1,c2,c3,c4;cin>>c1>>c2>>c3>>c4;
    if(c1==c3){cout<<1;xi=1;}
    else cout<<0;
    if(xi&&c2.substr(0,2)==c4.substr(0,2)){cout<<1;pa=1;}
    else cout<<0;
    if(xi&&pa&&c2[2]<='C'&&c4[2]<='C'||xi&&pa&&c2[2]>='D'&&c4[2]>='D')cout<<1;
    else cout<<0;
    if(xi&&pa&&abs(c2[2]-c4[2])==1&&max(c2[2],c4[2])!='D')cout<<1;
    else cout<<0;
    return 0;
}

