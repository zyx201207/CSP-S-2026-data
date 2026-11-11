#include <bits/stdc++.h>
using namespace std;
string s1,s2;
int c1,c2;
char ss1,ss2;
int sn1,sn2;
bool n1,n2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin>>c1>>s1>>c2>>s2;
    sn1=int(s1[0])*10+int(s1[1]);  sn2=int(s2[0])*10+int(s2[1]);
    if(s1[2]=='A' || s1[2]=='B' || s1[2]=='C') n1=0;else n1=1;
    if(s2[2]=='A' || s2[2]=='B' || s2[2]=='C') n2=0;else n2=1;
    if(c1==c2) cout<<'1';
    else cout<<'0';
    if(c1==c2 && sn1==sn2) cout<<'1';
    else cout<<'0';
    if(c1==c2 && sn1==sn2 && n1==n2) cout<<'1';
    else cout<<'0';
    if(c1==c2 && sn1==sn2 && n1==n2 && (int(s1[2])-int(s2[2])==1||int(s1[2])-int(s2[2])==-1)) cout<<'1';
    else cout<<'0';
    return 0;
    }
