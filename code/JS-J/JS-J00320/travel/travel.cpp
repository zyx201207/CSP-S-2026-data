#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int w=0,a1=0,s1=0,d=0;
    int n,n1;
    string a,s;
    cin>>n>>a>>n1>>s;
    if(n==n1) w=1;
    if(w==1&&a[0]==s[0]&&a[1]==s[1]) a1=1;
    if(w==1&&a1==1&&((a[2]=='A'&&s[2]=='B')||(a[2]=='B'&&s[2]=='C')||(a[2]=='D'&&s[2]=='F')||(a[2]=='A'&&s[2]=='C')||(a[2]=='B'&&s[2]=='A')||(a[2]=='C'&&s[2]=='B')||(a[2]=='F'&&s[2]=='D')||(a[2]=='C'&&s[2]=='A'))) s1=1;
    if(w==1&&a1==1&&s1==1&&((a[2]=='A'&&s[2]=='B')||(a[2]=='B'&&s[2]=='C')||(a[2]=='D'&&s[2]=='F')||(a[2]=='B'&&s[2]=='A')||(a[2]=='C'&&s[2]=='B')||(a[2]=='F'&&s[2]=='D'))) d=1;
    cout<<w<<a1<<s1<<d<<endl;
    return 0;
}