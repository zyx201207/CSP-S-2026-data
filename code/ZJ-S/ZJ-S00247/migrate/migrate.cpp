#include<bits/stdc++.h>
using namespace std;
#define ll long long
int C,T,n,ans,used[15],c[15],lst[15][15],f[15][15];
ll loc[15],xx[15];
ll d;
ll Abs(ll x){
	if(x>0)return x;
	return -x;
}
void dg(int x){
	if(x>=3){
		if(c[1]>c[x-1]){
			if(x==n+1)return ;
			else goto A;
		}
		for(int i=2;i<x;i++){
			if(Abs(xx[c[i]]-xx[c[i-1]])>d){
				if(x==n+1)return ;
				else goto A;
			}
		}
		if(lst[c[1]][c[x-1]]==-1){
			lst[c[1]][c[x-1]]=x-1-1;
			f[c[1]][c[x-1]]=1;
		}
		else{
			if(x-1-1<lst[c[1]][c[x-1]]){
				lst[c[1]][c[x-1]]=x-1-1;
				f[c[1]][c[x-1]]=1;
			}
			else if(x-1-1==lst[c[1]][c[x-1]]){
				f[c[1]][c[x-1]]++;
			}
		}
		if(x==n+1)return ;
	}
	A:
	for(c[x]=1;c[x]<=n;c[x]++){
		if(used[c[x]])continue;
		used[c[x]]=1;
		dg(x+1);
		used[c[x]]=0;
	}
}
void work(){
	memset(f,0,sizeof(f));
	memset(used,0,sizeof(used));
	memset(c,0,sizeof(c));
	memset(lst,-1,sizeof(lst));
	ans=0;
	cin>>n;
	cin>>d;
	for(int i=1;i<=n;i++)cin>>xx[i];
	dg(1);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(f[i][j]==2)ans++;
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>T;
	while(T--)work();
	return 0;
}