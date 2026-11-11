#include<bits/stdc++.h>
using namespace std;
string s1,c1,s2,c2;
int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>c1>>s2>>c2;
    int t=(s1[0]-'0')*10+(s1[1]-'0');
    int y=(s2[0]-'0')*10+(s2[1]-'0');
    if(t==y) cout<<1;
    else cout<<0;
    int r=(c1[0]-'0')*10+(c1[1]-'0');
    int p=(c2[0]-'0')*10+(c2[1]-'0');
    if(r==p && t==y) cout<<1;
    else cout<<0;
    if(t==y && r==p && ((c1[2]>='A' && c1[2]<='C' && c2[2]>='A' && c2[2]<='C') || (c1[2]>='D' && c1[2]<='F' && c2[2]>='D' && c2[2]<='F'))){
        cout<<1;
    } else {
        cout<<0;
    }
    int o=c1[2]-'A';
    int u=c2[2]-'A';
    if(t==y && r==p && ((c1[2]>='A' && c1[2]<='C' && c2[2]>='A' && c2[2]<='C') || (c1[2]>='D' && c1[2]<='F' && c2[2]>='D' && c2[2]<='F'))){
        if(abs(o-u)==1 && (c1[2]!='C' || c2[2]!='D')){
            cout<<1<<endl;
        } else {
            cout<<0<<endl;
        }
    } else {
        cout<<0<<endl;
    }
    return 0;
}
