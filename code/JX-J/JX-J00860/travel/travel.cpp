#include<bits/stdc++.h>
using namespace std;
int AAN[5];
int main()
{
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
for(int i=1;i<=4;++i)
{
    AAN[i]=0;
}
int a,b;
int c,d;
char e,f;
cin>>a>>b>>e>>c>>d>>f;
if(a==c)
    AAN[1]=1;
    if(AAN[1]==1)
if(b==d)
    AAN[2]=1;
    if(AAN[2]==1)
    {
       if(e=='A')
{
    if(f=='B')
    {
        AAN[3]=1;AAN[4]=1;
}
if(f=='C')
{
    AAN[3]=1;AAN[4]=0;
}
if(f=='D')
{
    AAN[3]=0;AAN[4]=0;
}
if(f=='F')
{
    AAN[3]=0;AAN[4]=0;
}
    }


    if(e=='B')
    {
     if(f=='A')
    {
        AAN[3]=1;AAN[4]=1;
}
if(f=='C')
{
    AAN[3]=1;AAN[4]=1;
}
if(f=='D')
{
    AAN[3]=0;AAN[4]=0;
}
if(f=='F')
{
    AAN[3]=0;AAN[4]=0;
}
    }

    if(e=='C')
    {
     if(f=='A')
    {
        AAN[3]=1;AAN[4]=0;
}
if(f=='B')
{
    AAN[3]=1;AAN[4]=1;
}
if(f=='D')
{
    AAN[3]=0;AAN[4]=0;
}
if(f=='F')
{
    AAN[3]=0;AAN[4]=0;
}
    }



      if(e=='D')
    {
        if(f=='F')
        {
        AAN[3]=1;AAN[4]=1;
        }
        else
        {
            AAN[3]=0;AAN[4]=0;
        }
}
if(e=='F')
    {
        if(f=='D')
        {
        AAN[3]=1;AAN[4]=1;
        }
        else
        {
            AAN[3]=0;AAN[4]=0;
        }
}
    }

cout<<AAN[1]<<AAN[2]<<AAN[3]<<AAN[4]<<"\n";
  return 0;
  }
