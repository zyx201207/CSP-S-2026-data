#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    int a=0,b=0,c=0,d=0;
    cin>>c1>>s1>>c2>>s2;
    if(c1[0]==c2[0]&&c1[1]==c2[1])a++;
    if(a&&s1[0]==s2[0]&&s1[1]==s2[1])b++;
    bool e=(s1[2]>='A'&&s2[2]>='A'&&s1[2]<='C'&&s2[2]<='C'),f=(s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D');
    if(b&&(e||f))c++;
    if(c&&f)d++;
    else{
        int diff=s1[2]-s2[2];
        if(diff<0)diff=-diff;
        if(c&&diff==1)d++;
    }
    cout<<a<<b<<c<<d;
    return 0;
}
