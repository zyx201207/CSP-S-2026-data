#include<bits/stdc++.h>
using namespace std;
string a,a1,b,b1;
int main(){
    freopen("area.in","r",stdin);
    freopen("area.out","w",stdout);
    cin>>a>>a1>>b>>b1;
    if(a==b) cout<<"1";
    else cout<<"0";
    if(a[1]==b[1] and a[0]==b[0]) cout<<"1";
    else cout<<"0";
    if(a1[2]>='A' and a1[2]<='c' and b1[2]>='A' and b1[2]<='c') cout<<"1";
    else if(a1[2]>='D' and a1[2]<='F' and b1[2]>='D' and b1[2]<='F') cout<<"1";
    else cout<<"0";
    if(a1[2]+1==b1[2] or a1[2]-1==b1[2]) cout<<"1";
    else cout<<"0";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
