//update 2025CSP-J T3 xor ac


#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=(int)(2e5+10);
int a[N];

int maxn=0;
int n,m;

bool cmp(int rr, int rj)
{
    return (rr < rj) ? 0 : 1;
}

void j_dfs(int i, int v, int nowm, int nowand)
{

    //     cout<<maxn<<' ';
    if(nowm==m)maxn=max(maxn, nowand);
    if(nowm==m||i>=n)return ;
    //if choose this value
    int k=(v&nowand);
    //cout<<k<<endl;
    if(k!=0)j_dfs(i+1, a[i+1], nowm+1, k);
    j_dfs(i+1, a[i+1], nowm, nowand);
}


void _do1()
{
    sort(a, a+n, cmp);
    //for(int i=0;i<n;i++)cout<<a[i];
    for(int i=0;i<n;i++)
    {
        j_dfs(i, a[i], 0, a[i]);
    }
    cout<<maxn;
    return ;
}

void _do2()
{
    sort(a, a+n, cmp);
    cout<<a[0];
    return ;
}

void _do3()
{
    int ans=a[0];
    for(int i=1;i<n;i++)
    {
        int k=(ans&a[i]);
        ans=k;
    }
    cout<<ans;
    return ;
}

void _do4()
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
    {
        if(i==j)continue;
        int k=(a[i]&a[j]);
        maxn=max(maxn, k);
    }
    cout<<maxn;
    return ;
}

void dfs_do5(int i, int nowand, bool ift)//the positive of now   the answer of now    if it had continued
{
    if(i==n)
    {
        maxn=max(maxn, nowand);
        return ;
    }
    if(ift==1)dfs_do5(i+1, (nowand&a[i]), 1);
    else
    {
        ift=1;
        dfs_do5(i+1, nowand, 1);
        ift=0;
        dfs_do5(i+1, (nowand&a[i]), 1);
    }
}

void _do5()
{
    dfs_do5(0, 0, 0);
}

int num1=0,num2=0,num3=0,num0=0;

void _do8()
{
    if(num3!=0)
    {
        maxn=3;
        m-=num3;
        num3=0;
    }
    if(m<0)
    {
        cout<<maxn;
        return ;
    }
    if(num2!=0)
    {
        maxn=2;
        m-=num2;
        num2=0;
    }
    if(m<0)
    {
        cout<<maxn;
        return ;
    }
    if(num1!=0)
    {
        maxn=1;
        m-=num1;
        num1=0;
    }
    if(m<0)
    {
        cout<<maxn;
        return ;
    }
    cout<<0;
    return ;
}

signed main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool all4=1;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>=4)all4=0;
        if(all4==1)
        {
            if(a[i]==1)num1++;
            if(a[i]==2)num2++;
            if(a[i]==3)num3++;
            if(a[i]==0)num0++;
        }
    }
    if(n<=20)
    {
        _do1();
        return 0;
    }
    if(m==1)
    {
        _do2();
        return 0;
    }
    if(m==n&&n<=2000)
    {
        _do3();
        return 0;
    }
    if(m==2&&n<=2000)
    {
        _do4();
        return 0;
    }
    if(m==n-1)
    {
        _do5();
        cout<<maxn;
        return 0;
    }
    if(all4==1)
    {
        _do8();
        cout<<maxn;
        return 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
