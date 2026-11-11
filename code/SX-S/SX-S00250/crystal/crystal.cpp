#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n,rt,ans=1;
bool already=0;
ll m,a[N],sum[N];
ll count(int L,int R){
	return (R-L)*a[R]-(sum[R-1]-sum[L-1]);
}
int main()
{
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	sum[1]=a[1];
	for(int i=2;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		if(already) continue;
		if(count(1,i)>m){
			already=1;
			rt=i-1;
			ans=i-1;
		}
	}
	if(!already){cout<<n;exit(0);}
	for(int lt=2;lt<n;lt++){
		while(count(lt,rt)<m&&rt<=n) rt++;
		if(count(lt,rt)>m) rt--;
		ans=max(ans,rt-lt+1);
		if(rt==n){cout<<ans;exit(0);}
	}
	cout<<ans;
	return 0;
}