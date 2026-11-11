#include <iostream>
using namespace std;
string s1,s2;
int c1,c2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    int a=(s1[0]-'0')*10+s1[1],b=(s2[0]-'0')*10+s2[1];
    char c=s1[2],d=s2[2];
    if(c1==c2) cout<<1;
    else cout<<0;
    if(c1==c2&&a==b) cout<<1;
    else cout<<0;
    if(c1==c2&&a==b&&(c<='C'&&d<='D'||c>'C'&&d>'D')) cout<<1;
    else cout<<0;
    if(c1==c2&&a==b&&abs(c-d)==1) cout<<1;
    else cout<<0;
    cout<<endl;
    return 0;
}
