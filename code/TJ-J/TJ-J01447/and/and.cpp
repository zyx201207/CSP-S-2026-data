#include<bits/stdc++.h>
using namespace std;
long long  n,m,a[200005],ans;
bool b[200005];
void dfs(long long m,long long  s){
	if(m==0){
		ans=max(ans,s);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(b[i]==0){
			b[i]=1;
			dfs(m-1,s&a[i]);
			b[i]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(m,(1<<31)-1);
	cout<<ans;
	return 0;
}


