#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans=-1e8;
long long a[200010];
int k[200010][32];
void dfs(int len,long long sum,int l){
	if(len==m){
		ans=max(ans,sum);
		return ;
	}
	for(int i=l;i<=n;i++){
		long long anns=0;
		for(int j=0;j<=30;j++){
			if(a[i]>>j&1==1&&sum>>j&1==1)anns+=pow(2,j);
		}
		dfs(len+1,anns,i+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	for(int i=1;i<=n;i++){
		dfs(1,a[i],i+1);
	}
	cout<<ans;
	return 0;
}