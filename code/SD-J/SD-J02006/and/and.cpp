#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,INF=0x3f3f3f3f;
int n,m,a[N],ans=-INF,mn,mx,sum;
bool flag;
void dfs(int cnt,int sum,int i){
	if(cnt==m){
		ans=max(ans,sum);
		return;
	}
	if(i==n+1) return;
	dfs(cnt,sum,i+1);
	dfs(cnt+1,sum&a[i],i+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>a[1];
	sum=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		mn=min(mn,a[i]);
		mx=max(mx,a[i]);
		sum&=a[i];
	}
	if(m==1){
		cout<<mx;
		return 0;
	}
	if(m==n){
		cout<<sum;
		return 0;
	}
	for(int i=1;i<=n;i++){
		dfs(1,a[i],i+1);
	}
	cout<<ans;
	return 0;
}
