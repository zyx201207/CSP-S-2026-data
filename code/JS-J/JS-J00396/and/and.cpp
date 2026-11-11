#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0,mx;
const int N=2e5+10;
long long a[N],b[N]={};
bool vis[N]={};
void dfs(int pos){
	if(pos==m+1){
		long long sum=b[1];
		for(int i=1;i<=m;i++){
			sum&=b[i];
		}
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			b[pos]=a[i];
			vis[i]=1;
			dfs(pos+1);
			vis[i]=0;
		}
	}
	return;
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(n>2000){
		sort(a+1,a+n+1);
		cout<<a[m];
		return 0;
	}
	else{
		dfs(1);
		cout<<ans;
	}
	return 0;
}
