#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500005],q[500005],f=1,w=1,ans=1;
int main()
{
 	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll num=1,sum=0;
	q[w]=a[1];
	for(int i=2;i<=n;i++){
		q[++w]=a[i];
		sum+=(a[i]-a[i-1])*num;
		num++;
		while(sum>m){
			sum-=(a[i]-q[f]);
			f++;
			num--;
		}
		if(num>ans){
			ans=num;
		}
	}
	cout<<ans;
	return 0;
}

