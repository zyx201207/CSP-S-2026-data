#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m,ans,last;
long long a[N],f[N];
void dfs(long long c,long long sum,long long x){
	if(c>m){
		if(sum>ans){
			ans=sum;
		}
		return ;
	}
	f[x]=1;
	for(int i=1;i<=n;i++){
		if(f[i]!=1){
			f[i]=1;
			dfs(c+1,sum&a[i],a[i]);
			f[i]=0;
		}
	}
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		ans=0;
		memset(f,0,sizeof(f));
		dfs(1,a[i],a[i]);
		last=max(last,ans);
	}
	cout<<last;
	return 0;
}
