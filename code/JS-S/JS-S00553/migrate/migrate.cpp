#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,sum,mn;
long long d,a[2000010];
void dfs(int l,int r,int cnt){
	if(l==r&&(mn==0||cnt==mn)){
		mn=cnt;
		sum++;
		return ;
	}
	for(int i=n;i>=l+1;i--){
		if(a[i]-a[l]<=d)
			dfs(i,r,cnt+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
				if(a[j]-a[i]>d){
					sum=0,mn;
					dfs(i,j,0);
					if(sum==2) ans++;
				}
		cout<<ans<<'\n';
	}
	return 0;
}