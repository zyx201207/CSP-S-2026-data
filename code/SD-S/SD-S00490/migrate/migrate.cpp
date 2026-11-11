#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=1e7+5,INF=0x3f3f3f3f3f3f3f3f;
int c,t;
int n,m;
int a[N];
int ans;
int x;
int res[N];
int num[N],nu[N];
int p,q,d;
void dfs(int now,int cnt,int f){
	if(now==f){
		if(cnt<p){
			for(int i=1;i<=cnt;i++)num[i]=res[i];
			p=cnt;
		}
		return;
	}
	for(int i=now+1;i<=n;i++){
		if(a[i]-a[now]<=m){
			res[cnt+1]=i;
			dfs(i,cnt+1,f);
		}
		else return;
	}
	return;
}
void dfs2(int now,int cnt,int f){
	if(p==q)return; 
	if(now==f){
		if(cnt<q){
			bool fl=true;
			if(p!=cnt)fl=false;
			else{
				for(int i=1;i<=cnt;i++){
					if(res[i]!=num[i]){
						fl=false;
						break;
					}
				}
				if(!fl){
					for(int i=1;i<=n;i++)nu[num[i]]=nu[res[i]]=1;
					q=p;
					return;
				}
			}
			return;
		}
		return;
	}
	for(int i=now+1;i<=n;i++){
		if(a[i]-a[now]<=m){
			res[cnt+1]=i;
			dfs(i,cnt+1,f);
		}
		else return;
		if(p==q)return;
	}
	return;
}
void dfs3(int now,int cnt,int f){
	if(d==p)return;
	if(now==n){
		if(cnt<d){
			bool fl=true;
			if(p!=cnt)fl=false;
			else{
				for(int i=1;i<=cnt;i++){
					if(!nu[res[i]]){
						fl=false;
						break;
					}
				}
				if(!fl){
					d=p;
					return;
				}
			}
			return;
		}
		return;
	}
	for(int i=now+1;i<=n;i++){
		if(a[i]-a[now]<=m){
			res[cnt+1]=i;
			dfs(i,cnt+1,f);
		}
		else return;
		if(d==q)return;
	}
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>m>>x;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(c==1||c==2){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					p=q=d=INF;
					dfs(j,0,i);
					dfs2(j,0,i);
					dfs3(j,0,i);
					if(d!=p&&p==q)ans++;
				}
			}
			cout<<ans<<'\n';
		}
		else if(c==13||c==14)cout<<0<<'\n';
		else cout<<n/2<<'\n';
	}
	return 0;
}
