#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <cmath>
using namespace std;
const int N=2e6+10;
int c,t,n,k,head[N],ans;
bool vis[N],op[N];
struct node{
	int u,v,nxt;
}e[N];
void dfs2(int x,int fa){
//	cout<<x<<" "<<fa<<"\n";
	for(int i=head[x];i!=0;i=e[i].nxt){
		if(e[i].v==fa) continue;
		if(op[e[i].v]){
			vis[e[i].v]=1;
			dfs2(e[i].v,x);
		}
	}
}
int dfs3(int x,int fa){
	if(op[x]) return 0;
	int sum1=n;
	for(int i=head[x];i!=0;i=e[i].nxt){
		if(e[i].v==fa) continue;
		sum1=min(sum1,1+dfs3(e[i].v,x));
	}
	return sum1;
}
void dfs(int dep,int sum1){
	if(dep==n+1||sum1==k){
//		cout<<"&*^*&"<<"\n";
		if(sum1!=k) return;
		for(int i=dep;i<=n;i++) op[i]=0;
		for(int i=1;i<=n;i++) vis[i]=0;
		int sum=0,opt=0;
		for(int i=1;i<=n;i++)
			if(!vis[i]&&op[i]){
//				cout<<"sd8f78"<<"\n";
				dfs2(i,0);
				opt++;
//				cout<<opt<<"\n";
			}
//		cout<<"*(%%^"<<'\n';
		if(opt<=2){
			for(int i=1;i<=n;i++) sum=max(sum,dfs3(i,0));
			ans=min(ans,sum);
		}
//		cout<<"*(%%^"<<'\n';
		return;
	}
	op[dep]=1;
	dfs(dep+1,sum1+1);
	op[dep]=0;
	dfs(dep+1,sum1);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		ans=n;
		for(int i=1;i<=n;i++) head[i]=0;
		for(int i=1;i<=n-1;i++){
			cin>>e[i].u>>e[i].v;
			e[i].nxt=head[e[i].u];
			head[e[i].u]=i;
		}
		dfs(1,0);
//		cout<<"*(^*%^"<<"\n";
		cout<<ans<<"\n";
	}
	return 0;
}

