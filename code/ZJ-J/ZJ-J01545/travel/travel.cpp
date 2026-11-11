#include<bits/stdc++.h>
#define int long long
using namespace std;
int x,y;
string s1,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>x>>s1>>y>>s2;
    if(x==y) cout<<"1";
    else cout<<"0";
    int a=0,b=0;
    a=(s1[0]-'0')*10+(s1[1]-'0');
    b=(s2[0]-'0')*10+(s2[1]-'0');
    if(x==y&&a==b) cout<<'1';
    else cout<<'0';
    int xx=(s1[2]-'A'+1),yy=(s2[2]-'A'+1);
    if(xx==6) xx=5;
    if(yy==6) yy=5;
    if(x==y&&a==b&&((xx<=3&&yy<=3)||(xx>3&&yy>3))) cout<<'1';
    else cout<<'0';
    if(x==y&&a==b&&((xx<=3&&yy<=3)||(xx>3&&yy>3))&&abs(xx-yy)==1) cout<<'1';
    else cout<<'0';
    return 0;
}
