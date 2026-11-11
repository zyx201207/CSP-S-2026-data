#include<bits/stdc++.h>
using namespace std;
long long C,T,n,d,a[2000005],ed,ans,cnt,an;
long long vis[2000005];
void dfs1(long long x,long long st){
	if(x==ed){
		ans=st;
		return ;
	}
	long long i=x;
	while(i+1<=ed){
		if(abs(a[x]-a[i+1])>d)break;
		i++;
	}
	if(i==x)return ;
	dfs1(i,st+1);
	return ;
}
void dfs2(long long x,long long st){
	if(st>ans)return ;
	if(x==ed){
		if(st==ans)cnt++;
		return ;
	}
	for(int i=x+1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		dfs2(i,st+1);
		vis[i]=0;
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--){
		memset(vis,0,sizeof(vis));
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		an=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ed=j;
				cnt=0;
				dfs1(i,0);
				dfs2(i,0);
				if(cnt==2){
					cout<<i<<' '<<j<<"\n";
					an++;
				}
			}
		}
		cout<<an<<'\n';
	}
	return 0;
}

