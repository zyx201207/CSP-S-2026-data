#include<bits/stdc++.h>
using namespace std;
int rcx,xcx;
char rl,xl;
string rzw,xzw;
int a[10],rp[10],xp[10];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>rcx>>rzw>>xcx>>xzw;
    a[1]=0;
    a[2]=0;
    a[3]=0;
    a[4]=0;
    for(int i=0;i<2;i++)
    {
        rp[i]=rzw[i]-'0';
        xp[i]=xzw[i]-'0';
    }
    rl=rzw[2];
    xl=xzw[2];
    if(rcx==xcx)
    {
        a[1]=1;
        if(rp[0]==xp[0]&&rp[1]==xp[1])
        {
            a[2]=1;
            if(rl=='A'||rl=='B'||rl=='C')
            {
                if(xl=='A'||xl=='B'||xl=='C')
                {
                    a[3]=1;
                    if(max(xl-'0',rl-'0')-min(xl-'0',rl-'0')==1)
                    {
                        a[4]=1;
                    }
                }
            }
            else
            {
                if(xl=='D'||xl=='F')
                {
                    a[3]=1;
                    if(max(xl-'0',rl-'0')-min(xl-'0',rl-'0')==1)
                    {
                        a[4]=1;
                    }
                }
            }
        }
    }
    cout<<a[1]<<a[2]<<a[3]<<a[4];
}
