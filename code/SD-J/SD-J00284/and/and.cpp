#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
int maxn=0;
int ansdfs;
int b[200010];
bool use[200010];

void dfs(int pos){
	if(pos==m+1){
		int num=b[1];
		for(int i=2;i<=m;i++){
			num=num&b[i];
		}
		ansdfs=max(ansdfs,num);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!use[i]){
			use[i]=1;
			b[pos]=a[i];
			dfs(pos+1);
			use[i]=0;
		}
		
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==1){
		cout<<maxn<<endl;
		return 0;
	}
	if(m==n){
		long long ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans<<endl;
		return 0;
	}
	if(m==2){
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				long long num=a[i]&a[j];
				ans=max(ans,num);
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	if(m<=20){
		dfs(1);
		cout<<ansdfs;
		return 0;
	}
	
	return 0;
}

