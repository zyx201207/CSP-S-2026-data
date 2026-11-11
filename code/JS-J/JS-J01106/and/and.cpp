#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000005];
int maxn=INT_MIN,cnt;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=n; j>=1; j--)
        {
            if(i==j) break;
            cnt=a[i]&a[j];
            maxn=max(cnt,maxn);
        }
    }
    cout<<maxn;
    return 0;
}

