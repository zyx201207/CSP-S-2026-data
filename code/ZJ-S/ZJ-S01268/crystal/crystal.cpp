#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,q[588888],pre[588888],ans=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	bool f=0;
	int as=0;
	for(int i=1;i<=n;i++){
		cin>>q[i];
		if(i>2&&!q[i-1]-q[i]==q[i-1]-q[i-2]){
			f=1;
		}
		as=q[i]-q[i-1];
	}
	if(!f){
		int k=1;
		while((k+1)*k/2*as<=m&&k<=n)k++;
		cout<<k-1;
		return 0;
	}
	sort(q+1,q+n+1);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+q[i];
	for(int i=1;i<=n;i++){
		for(int l=0;i+l<=n;l++){
			int p=q[i+l];
			//全变成一个数的值总和p*(l+1)
			//原始值总和pre[i+l]-pre[i-1]
			int ne=p*(l+1)-pre[i+l]+pre[i-1];
			if(ne<=m){
				ans=max(ans,l+1);
			}else{
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
