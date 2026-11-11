#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long c,t,n,d,x[N],ans,len; 
void dfs(int k,int en,int l){
	if(k==en){
		if(l<len){
			len=l;
			ans=1;
		}
		else if(l==len)
			ans++;
		return;
	}
	for(int i=k+1;i<=en;i++){
		if(x[i]-x[k]>d)return;
		dfs(i,en,l+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		int sum=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)
			scanf("%lld",&x[i]);
		for(int i=1;i<n;i++){
			for(int j=i+3;j<=n;j++){
				ans=0;
				len=1e9;
				dfs(i,j,1);
				if(ans==2)
					sum++;
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
}
