#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500010];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,as=0,sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1,j=1;i<=n;i++){
		sum+=(i-j)*(a[i]-a[i-1]);
		while(j+1<=i&&sum>m){
			sum-=a[i]-a[j];
			j++;
		}
		as=max(as,i-j+1);
	}
	cout<<as;
	return 0;
}