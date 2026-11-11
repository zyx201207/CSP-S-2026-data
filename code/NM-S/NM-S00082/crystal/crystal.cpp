#include<bits/stdc++.h>
using namespace std;
long long n,m;
const int maxn=5*1e5+3;
long long a[maxn],ans;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
		for(int i=1;(2*(a[2]-a[1])+(i-1)*(a[2]-a[1]))*i<=2*m;i++)
		{
			ans=i+1;
		}
	cout<<ans;
    return 0;
}
