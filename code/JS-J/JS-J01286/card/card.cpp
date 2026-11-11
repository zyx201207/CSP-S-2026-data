/*
CSP-J 2026 T4
Author:DFLJ

I finally lost.
Just code for bags.
11:24 I get 48pts;
11:28 I get 52pts;
11:48 I get 60pts;

Just a Step in length.
But I had no time.

100+100+100+60=360?

I'm so sorry.

Though I had a lot of training, I'm still weak enough.
Just a step between me and AK CSPJ.

_______

I was a small bird.
Tried my best to fly but can't fly so high.
One day the real storm came.
Got into the wind and I felt life.
*/
#include<bits/stdc++.h>
using namespace std;
int a[500001],b[500001],n,m,las[500001],lat[500001],ans[300001],cnt[300001],dv[500001];
void sol1()
{
    for(int i=1; i<=n; i++)
    {
        stack<int> stk;
        for(int j=1; j<=m; j++) cnt[j]=0;
        for(int j=i; j<=n; j++)
        {
            if(!cnt[a[j]])
            {
                stk.push(a[j]);
                cnt[a[j]]++;
            }
            else
            {
                int tmp;
                do{
                    tmp=stk.top();
                    stk.pop();
                    cnt[tmp]--;
                }while(tmp!=a[j]);
                stk.push(a[j]);
                cnt[a[j]]++;
            }
        }
        while(!stk.empty())
        {
            int tmp=stk.top();
            stk.pop();
            ans[tmp]++;
            //cout<<tmp<<' ';
        }
        //cout<<'\n';
    }
    for(int i=1; i<=m; i++) cout<<ans[i]<<' ';
}
void solA()
{
    for(int i=1; i<=n; i++) ans[a[i]]=i;
    for(int i=1; i<=m; i++) cout<<ans[i]<<' ';
}
void solC()
{
    ans[a[n]]=n;
    for(int i=1; i<=n; i++)
    {
        if(a[i]!=a[n]) ans[a[i]]++;
    }
    for(int i=1; i<=m; i++) cout<<ans[i]<<' ';
}
void solB()
{
    int tn=0,sum=0;
    for(int i=1; i<=n; i++)
    {
        if(a[i]!=a[i-1]) b[++tn]=a[i];
        else dv[a[i]]++;
    }
    for(int i=1; i<=tn; i++)
    {
        stack<int> stk;
        for(int j=1; j<=m; j++) cnt[j]=0;
        for(int j=i; j<=tn; j++)
        {
            if(!cnt[b[j]])
            {
                stk.push(b[j]);
                cnt[b[j]]++;
            }
            else
            {
                int tmp;
                do{
                    tmp=stk.top();
                    stk.pop();
                    cnt[tmp]--;
                }while(tmp!=b[j]);
                stk.push(b[j]);
                cnt[b[j]]++;
            }
        }
        while(!stk.empty())
        {
            int tmp=stk.top();
            stk.pop();
            ans[tmp]++;
            //cout<<tmp<<' ';
        }
        //cout<<'\n';
    }
    for(int i=1; i<=m; i++) 
    {
        if(i==a[n]) cout<<n<<' ';
        else cout<<ans[i]+dv[i]<<' ';
    }
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++) cin>>a[i],lat[a[i]]=i;
    if(n<=5000&&m<=3000)
    {
        sol1();
        return 0;
    }
    if(m>3000)
    {
        solA();
        return 0;
    }
    if(m<=2)
    {
        solC();
        return 0;
    }
    if(m<=3000)
    {
        solB();
        return 0;
    }
    return 0;
}