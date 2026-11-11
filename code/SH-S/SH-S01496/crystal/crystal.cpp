#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
long long m,power[500005],pre[500005],ans;
bool flaga=1,flagb=1;
//const ll POWER_MAX=1e12;
//bool cmp(ll a,ll b){
//	return (a+POWER_MAX<b+POWER_MAX);
//}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>power[i];
	}
	sort(&power[1],&power[n+1]);
	for (int i=1;i<n;i++){
		pre[i]=power[i+1]-power[i];
		if (pre[i]!=1) flaga=0;
		if (pre[i]!=pre[i-1]&&i>1) flagb=0;
	}
	//ll pre_now=1e18;
	for (int i=n;i>0;i--){
		ll now=power[i],oper=m,temp_ans=0;
		for (int j=i;j>0;j--){
			if (now-power[j]<=oper){
				temp_ans++;
				oper-=(now-power[j]);
			}
			else break;
		}
		ans=max(temp_ans,ans);
		if (ans>=i-1) break;
		if (flaga||flagb) break;
	}
	cout<<ans;
	return 0;
}
