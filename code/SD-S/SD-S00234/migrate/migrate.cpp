#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long a[N];
int n,ed,ans=1e9;
long long d;
int cnt=0;
void dfs(int x,int step){
	if(step>ans) return;
	if(x==ed){
		if(step<ans){
			ans=step;
			cnt=1;
		}else if(step==ans) cnt++;
		return;
	}
	for(int i=x+1;i<=n;i++){
		if(a[i]-a[x]<=d) dfs(i,step+1);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int Ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ed=j;
				dfs(i,0);
				if(cnt==2) Ans++;
				cnt=0;
				ans=1e9;
			}
		}
		cout<<Ans<<"\n";
	}
	return 0;
}


