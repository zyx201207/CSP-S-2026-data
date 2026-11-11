#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5*1e5+5;
int n;
ll m,a[N],pre[N];
bool cmp(ll frs,ll scd){
	return frs<scd;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	memset(pre,0,sizeof(pre));
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}

	
	sort(a+1,a+1+n,cmp);
	
	if(n>=5000){
		ll d=a[1]-a[0];
		ll	num=m/d;
		int k=1;
		while((1+k)*k/2<=m){
			k++;
		}
		cout<<k-1;
		return 0;
	}
	
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			ll t=a[i]*(i-j)-pre[i-1]+pre[j-1];
			if(t<=m){
				ans=max(i-j+1,ans);
				break;
			}
		}
	}
	
	cout<<ans;
	return 0;
}

