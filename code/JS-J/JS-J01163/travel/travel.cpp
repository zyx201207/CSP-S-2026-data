#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c1>>s1>>c2>>s2;
    bool f1,f2,f3,f4;
    f1=f2=f3=f4=0;
    if(c1==c2) f1=1;
    int a,b;
    a=(s1[0]-'0')*10+s1[1]-'0';
    b=(s2[0]-'0')*10+s2[1]-'0';
    if(f1&&a==b) f2=1;
    char c,d;
    c=s1[2];d=s2[2];
    if(f1&&f2){
        if((c=='A'&&d=='B')||(c=='A'&&d=='C')||(c=='B'&&d=='A')||(c=='B'&&d=='C')||(c=='C'&&d=='B')||(c=='C'&&d=='A')){
            f3=1;
        }
        if((c=='D'&&d=='F')||(c=='F'&&d=='D')) f3=1;
    }
    if(f1&&f2&&f3){
        if((c=='A'&&d=='B')||(c=='B'&&d=='A')) f4=1;
        else if((c=='B'&&d=='C')||(c=='C'&&d=='B')) f4=1;
        else if((c=='D'&&d=='F')||(c=='F'&&d=='D')) f4=1;
    }
    if(f1) cout<<1;
    else cout<<0;
    if(f2) cout<<1;
    else cout<<0;
    if(f3) cout<<1;
    else cout<<0;
    if(f4) cout<<1;
    else cout<<0;
    return 0;
}
