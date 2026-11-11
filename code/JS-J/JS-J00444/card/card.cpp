#include<bits/stdc++.h>
using namespace std;
int a[210000],n,m,b[210000],t[310000],v[310000],zhuo[210000];
void play(int time,int zh)
{
    int u=1;
    for(int i=1;i<=time;i++)
    {
        if(t[a[i]]==0)
        {
            zhuo[zh]=a[i];
            a[i]=0;
            zh++;
            t[a[i]]++;
        }
        else{
                int flag=0;
                while(flag==0)
                {
                    b[u]=zhuo[zh-1];
                    u++;
                    zh--;
                    if(zhuo[zh-1]==a[i])
                    {
                        flag=1;
                    }
                }
                zhuo[zh]=a[i];
        }
    }
    int z=time+1,time1=0;
    while(1==1)
    {
        if(a[z]==0) break;
        else
        {
            time1++;
            a[z-time]=a[z];
        }
    }
    for(int i=1;i<=u-1;i++)
    {
        a[time1+i]=b[i];
    }
    for(int i=1;i<=zh;i++)
    {
        t[zhuo[i]]++;
    }
    for(int i=1;i<=m;i++)
    {
        if(t[i]!=0)
        {
            v[i]++;
        }
    }
    return;
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        play(n,1);
    }
    for(int i=1;i<=m;i++)
    {
        cout<<0<<endl;
    }
    return 0;
}
