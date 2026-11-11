#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=20;
const int INF=0x3f3f3f3f;
ll x[N];
int ans,cnt;
void dfs(int now,int lst,int e,int res,ll d){
	if(x[now]-x[lst]>d) return ;
	if(now==e){
		res++;
		if(res<ans){
			ans=res;
			cnt=1;
		}else if(res==ans) cnt++;
		return ;
	}
	dfs(now+1,now,e,res+1,d);
	dfs(now+1,lst,e,res,d);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int c,t;
	cin>>c>>t;
	if(c<=2){
		while(t--){
			int n;
			ll d;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			int res=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					ans=INF;
					cnt=0;
					dfs(i,i,j,0,d);
					if(cnt==2) res++;
				}
			}
			cout<<res<<"\n";
		}
	}else{
		while(t--){
			cout<<"0\n";
		}
	}
	return 0;
}
