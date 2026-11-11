#include<bits/stdc++.h>
using namespace std;
int n,m,b[200010],t;
long long a[200010],res;
bool cmp(int x,int y){
	return x>y;
}
void dfs(int x){
	if(t==m){
		long long s=a[b[1]];
		for(int i=2;i<=t;i++) s=(s&a[b[i]]);
		res=max(res,s);
		return;
	}
	if(x==n+1) return;
	b[++t]=x;
	dfs(x+1);
	t--;
	dfs(x+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=20){
		dfs(1);
		cout<<res;
		return 0;
	}
	if(n==m){
		long long ans=a[1];
		for(int i=2;i<=n;i++) ans=(ans&a[i]);
		cout<<ans;
		return 0;
	}
	if(n<=2000&&m==2){
		long long maxn=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn,(a[i]&a[j]));
			}
		}
		cout<<maxn;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	cout<<a[m];
	return 0;
}
