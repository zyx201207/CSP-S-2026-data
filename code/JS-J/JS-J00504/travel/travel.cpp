#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+7;
string c1,s1,c2,s2;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    int n1=(s1[0]-'0')*10+(s1[1]-'0');
    int n2=(s2[0]-'0')*10+(s2[1]-'0');
    char m1=s1[2],m2=s2[2];
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    if(n1!=n2){
        cout<<"1000";
        return 0;
    }
    if(m1>m2) swap(m1,m2);
    if(m1>='A'&&m1<='C'&&m2>='D'&&m2<='F'){
        cout<<"1100";
        return 0;
    }
    if((m2=='B'&&m1=='A')||(m2=='C'&&m1=='B')||(m2=='F'&&m1=='D'))
        cout<<"1111";
    else cout<<"1110";
    return 0;
}
