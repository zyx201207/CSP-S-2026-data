#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],sum,gs,ans,st[500005],t,h=1;
int main(){
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	//从小到大排序
	a[0]=a[1];
	for(int i=1;i<=n;i++){//枚举最大值
		sum+=gs*(a[i]-a[i-1]);
		gs++;
		st[++t]=a[i];
		while(h<=t&&sum>m){
			sum-=(a[i]-st[h]);
			h++;
			gs--;
		}
		ans=max(ans,gs);
	}
	cout<<ans;
	return 0;
}