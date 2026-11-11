#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int r[20],x[20];
bool a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    r[1]=s1[0]+s1[1];
    x[1]=s2[0]+s2[1];
    r[2]=s1[2];
    x[2]=s2[2];
    if(r[2]=='E'||r[2]=='F')r[2]++;
    if(x[2]=='E'||x[2]=='F')x[2]++;

    if(c1==c2)a=1;
    if(r[1]==x[1]&&a==1)b=1;
    if(b==1&&a==1){
        if(abs(r[2]-x[2])==2)c=1;
        else if(abs(r[2]-x[2])==1)c=1,d=1;
    }
    cout<<a<<b<<c<<d;
    return 0;
}
