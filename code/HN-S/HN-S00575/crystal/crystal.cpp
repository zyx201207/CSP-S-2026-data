#include<bits/stdc++.h>
using namespace std;
long long n;
long long m;
int a[500000];
int a1[500000];
int main()
{
    //freopen("crystal.in","r",stdin);
    //freopen("crystal.out","w",stdout);
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];

    }
    sort(a+1,a+n+1);
    a[0]=a[1];
    for(int i=1;i<=n;i++)
    {
        a1[i]=a[i]-a[i-1];
    }

    long long cnt=0;
    int ans=0;
    int ans_finally=0;
    for(int i=1;i<=n;i++)
    {
        while(cnt<m)
    {
        cnt+=a1[ans+i];
        if(cnt>m)break;
        if(ans+i-1>n) break;
        ans++;
    }
    if(ans>=ans_finally)
    {
        ans_finally=ans;
        ans=0;
        cnt=0;
    }
    else{
        ans=0;
        cnt=0;
    }
    }
    //for(int i=1;i<=n;i++)
    //{
        //cout<<a1[i]<<" ";
    //}

cout<<ans_finally+1;
//cout<<a1[1];

    return 0;
}
