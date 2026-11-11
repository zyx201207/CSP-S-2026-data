#include<bits/stdc++.h>;
using namespace std;
#define int long long
int c1,c2,a[10];
string s1,s2;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        a[1]=1;
    }
    if((s1[0]==s2[0]&&s1[1]==s2[1])&&a[1]==1){
        a[2]=1;
    }
    if(a[2]==1&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))){
        a[3]=1;
    }
    if(abs(s1[2]-s2[2])==1&&a[3]==1){
        a[4]=1;
    }
    cout<<a[1]<<a[2]<<a[3]<<a[4];
}
