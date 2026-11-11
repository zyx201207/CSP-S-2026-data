#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
ll m;
int ans=0;
ll a[510000];
int main()
{
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=2;i--){
		ll num=0;
		int sum=1;
		for(int j=i-1;j>=1;j--){
			num+=a[i]-a[j];
			if(num>m){
				break;
			}
			sum++;
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
