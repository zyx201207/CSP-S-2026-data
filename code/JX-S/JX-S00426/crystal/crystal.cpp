#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,m,ans;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    long long l=a[1],r=a[n];
    for(int i=l;i<=r;i++)
    {
        vector<long long> s;
        for(int j=1;j<=n;j++)
        {
            if(a[j]<=i)
                s.push_back(i-a[j]);
            else break;
        }
        long long sum=0,mm=m;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(mm>=s[i])
            {
                sum++;
                mm-=s[i];
            }
        }
        ans=max(ans,sum);
    }
    cout<<ans;
    return 0;
}
