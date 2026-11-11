#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500002];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
    {
        int num=1;
        long long c=0;
        for(int j=i-1;j>=1;j--)
        {
            c+=(a[i]-a[j]);
            if(c>m) break;
            num++;
        }
        if(num>ans) ans=num;
    }
    cout<<ans;
    return 0;
}
