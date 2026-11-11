#include<bits/stdc++.h>
using namespace std;
long long n,m,s[200005],a[200005],sum=1073741823,ans;
bool mark[200005];
void dfs(int x){
	if(x>m){
		for(int i=1;i<x;i++){
			sum=sum&a[i];
		}
		ans=max(ans,sum);
		sum=1073741823;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(mark[i]==false){
			mark[i]=true;
			a[x]=s[i];
			dfs(x+1);
			mark[i]=false;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		mark[i]=false;
	}
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	if(n==m){
		for(int i=1;i<=n;i++){
			sum=sum&s[i];
		}
		cout<<sum;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
