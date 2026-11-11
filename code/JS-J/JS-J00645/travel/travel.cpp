#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a,b;
char c,d;
bool f1,f2;
void f(){
    c=s1[2],d=s2[2];
    if(s1[0]=='1') a+=10;
    if(s2[0]=='1') b+=10;
    a+=s1[1]-'0',b+=s2[1]-'0';
    if(c=='A'||c=='B'||c=='C') f1=true;
    if(d=='A'||d=='B'||d=='C') f2=true;
    return;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    f();
    if(c1!=c2) cout<<"0000";
    else{
        cout<<1;
        if(a!=b) cout<<"000";
        else{
            cout<<1;
            if(f1!=f2) cout<<"00";
            else{
                cout<<1;
                if(!f1) cout<<1;
                else if(abs(c-d)==1) cout<<1;
                else cout<<0;
            }
        }
    }
    return 0;
}