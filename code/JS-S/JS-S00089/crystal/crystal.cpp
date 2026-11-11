#include<bits/stdc++.h>
using namespace std;
long long int n,m;
long long int a[550000],s[550000];
int kk(long long int left,long long int right)
{
    if(left==right) return 0;
    long long int mid=left+(right-left)/2;
    return a[right]*(right-left)-s[right-1]+s[left-1];
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        s[i]=s[i-1]+a[i];
    }
    long long int left=1,maxn=0,right=1;
    while(left<=n)
    {
        while(kk(left,right)<=m && right<=n)
        {
            right++;
        }
        right--;
        if(right-left+1>=maxn)
        {
            maxn=right-left+1;
        }
        left++;
    }
    cout<<maxn<<'\n';
    return 0;
}
