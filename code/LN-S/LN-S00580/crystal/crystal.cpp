#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N=5e5+5;
int n;
ll m;
ll a[N],cnt,ans,l,r;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(l=1,r=1;r<=n;r++)
    {
        cnt+=(a[r]-a[r-1])*(r-l);
        //cout<<l<<" "<<r<<" : "<<cnt<<'\n';
        while(cnt>m&&l<r)
        {
            cnt-=a[r]-a[l];
            l++;
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans<<'\n';
    return 0;
}

/*
求你了一定要AC喵
已经无能为力了喵
红紫黑黄的不要喵
芙兰朵露脚香香喵
*/
