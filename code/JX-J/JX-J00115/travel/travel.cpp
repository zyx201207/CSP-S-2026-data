
#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie();
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    bool b1=false,b2=false,b3=false,b4=false;
    string t1=s1.substr(0,2);
    string t2=s2.substr(0,2);
    if(c1==c2) b1=true;
    if(c1==c2&&t1==t2) b2=true;
    string tt1=s1.substr(2,3),tt2=s2.substr(2,3);
    char d1=tt1[0],d2=tt2[0];
    if(c1==c2&&(int)d1-(int)d2==1&&(int)d2-(int)d1==1)
        b4=true;
    if((d1=='C'&&d2=='D')||(d1=='D'||d2=='C'))
        b4=false;
    if(c1==c2&&t1==t2&&(d1<='C'&&d2<='C'))
        b3=true;
    if(c1==c2&&t1==t2&&(d1>'C'&&d2>'C'))
        b3=true;
    cout<<b1<<b2<<b3<<b4<<endl;
    return 0;
}
