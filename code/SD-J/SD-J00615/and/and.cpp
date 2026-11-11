#include<bits/stdc++.h>
using namespace std;
const int MA=2*1e5;
int n,m;
long long a[MA],v[MA],s[MA],ans;
void dfs(int k){
	if(k>m){
		long long sum=0x0f;
		for(int i=1;i<=m;i++){
			sum=sum&s[i];
		}
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		if(v[a[i]]==0)continue;
		s[k]=a[i];
		v[a[i]]--;
		dfs(k+1);
		v[a[i]]++;
	}
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	memset(v,0,sizeof(v));
	for(int i=1;i<=n;i++){
		cin>>a[i];
		v[a[i]]++;
	}
	
	dfs(1);
	cout<<ans;
	return 0;
}
