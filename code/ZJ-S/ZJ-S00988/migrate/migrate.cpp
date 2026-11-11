#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N=1e6+5;
int c,n,m,a[N],ans,tp,cnt;
void dfs(int x,int ed,int s){
	if(a[x]==ed&&s==tp){
		cnt++;
		return ;
	}if(s>tp)return ;
	for(int i=x+1;i<=n;i++){
		if(a[i]-a[x]<=m){
			dfs(i,ed,s+1);
		}
	}
}
void solve(){
	cin>>n>>m;ans=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(c==0||c==1||c==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if((a[j]-a[i])%m==0)tp=(a[j]-a[i])/m;
				else tp=(a[j]-a[i])/m+1;
				cnt=0;
				dfs(i,a[j],0);
	//			cout<<cnt<<'\n';
	//			if(cnt==2){
	//				cout<<a[i]<<' '<<a[j]<<'\n';
	//			}
				ans+=(cnt==2);
			}
		}
		cout<<ans<<'\n';
		return ;
	}
	cout<<"0\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	init();
	int T=1;
	cin>>c>>T;
	while(T--)solve();
	return 0;
}

