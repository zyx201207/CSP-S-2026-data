#include<bits/stdc++.h>
using namespace std;
long long n;
long long m; 
long long a[200010];
long long ans=-1;
bool f[200010];
void dfs(long long pos,long long sum,long long cho){
	if(cho==m){
		if(sum>=ans){
			ans=sum;
		}
		return;
	}
	for(long long i=pos+1;i<=n;i++){
		if(!f[i]){
			if(cho==0)
			{
			f[i]=1;
			dfs(i,a[i],cho+1);
			f[i]=0;
			}
			else{
			f[i]=1;
			dfs(i,sum&a[i],cho+1);
			f[i]=0;
			}
			
		}
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0);
	cout<<ans;
	return 0;
} 
