#include<iostream>
#include<cstdio>
using namespace std;
string c1,s1,c2,s2;
bool a,b,c,d;
int x[128][128];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    for(int i='A';i<='C';++i)
        for(int j='A';j<='C';++j)
            if(i==j)continue;
            else x[i][j]=1;
    for(int i='D';i<='F';++i)
        for(int j='D';j<='F';++j)
            if(i==j)continue;
            else x[i][j]=1;
    if(c1==c2)a=1;
    if(a && s1[0]==s2[0] && s1[1]==s2[1])b=1;
    if(a && b && x[ s1[2] ][ s2[2] ])c=1;
    if(a && b && c && abs(s1[2]-s2[2])==1)d=1;
    cout<<a<<b<<c<<d;
    return 0;
}
