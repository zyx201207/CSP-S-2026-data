#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
int c,t,n,ans;
long long d,a[N];
int dis,cnt;
void dfs(int u,int v,int val,int ste,long long cost){
	if(val==v){
		if(ste<dis){
			dis=ste;
			cnt=1;
			return ;
		}
		else if(ste==dis){
			cnt++;
			return ;
		}
	}
	if(a[val+1]-a[val]>d){
		return ;
	}
	if(a[val+1]-a[val]+cost<=d){
		dfs(u,v,val+1,ste,cost+a[val+1]-a[val]);
		dfs(u,v,val+1,ste+1,0);
		return ;
	}
	else{
		dfs(u,v,val+1,ste+1,0);
		return ;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n<=3){
			cout<<0<<'\n';
			continue;
		}
		ans=0;
		for(int i=1;i<=n-3;i++){
			for(int j=i+3;j<=n;j++){
				dis=2000010;
				cnt=0;
				if(cnt==2){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
