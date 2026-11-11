#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char a[11];
int x,y,n,m;
bool f,h;
int main()
{
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>c1>>s1>>c2>>s2;
if(c1==c2)
    a[1]='1';
else
    a[1]='0';
if(s1[0]=='1')
    x=(s1[0]-'0')*10+(s1[1]-'0');
else
    x=s1[1]-'0';
if(s2[0]=='1')
    y=(s2[0]-'0')*10+(s2[1]-'0');
else
    y=s2[1]-'0';
if(x==y&&a[1]=='1')
    a[2]='1';
else
    a[2]='0';
if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')
    f=true;
else if(s1[2]=='D'||s1[2]=='F')
    f=false;
if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
    h=true;
else if(s1[2]=='D'||s1[2]=='F')
    h=false;
if(f==h&&a[2]=='1')
    a[3]='1';
else
    a[3]='0';
n=s1[2]-'A';
m=s2[2]-'A';
if(abs(n-m)&&a[3]=='1')
    a[4]='1';
else
    a[4]='0';
for(int i=1;i<=4;i++)
    cout<<a[i];
cout<<endl;
fclose(stdin);
fclose(stdout);
return 0;
}
