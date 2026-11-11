#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
string b,d;
int a,c,p=0,wc=0,wd=0,bb=0,t=0;
cin>>a>>b>>c>>d;
if(a==c)
{
cout<<1;
p++;
}else
{
    cout<<0;
}
string b1=b.erase(2,1);
string d1=d.erase(2,1);
if(d1==b1&&p==1)
{
cout<<1;
p++;
}else
{
    cout<<0;
}
string b2=b.erase(1,2);
string d2=d.erase(1,2);

if(b2=="A"||b2=="C"||b2=="B")
{
wc+=1;
}if(d2=="A"||d2=="C"||d2=="B")
{
wd+=1;
}
if(b2=="D"||b2=="F")
{
wc+=2;
}
if(d2=="D"||d2=="F")
{
wd+=2;
}
if(p==2&&wc==wd)
{
    cout<<1;
    p++;
}else
{
    cout<<0;
}



if(p==3)
{
 cout<<1;
}else
{
    cout<<0;
}

return 0;
}
