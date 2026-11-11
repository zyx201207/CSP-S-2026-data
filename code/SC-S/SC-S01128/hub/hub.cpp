#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

const int N=1e6+5;
int c,t;
int n,k;
int d[N][2];
int e[N<<1],ne[N<<1],h[N],idx;

void add(int a,int b){
	e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dfs(int u,int fa){
	int ma=0,ma2=0;
	for(int i=h[u];~i;i=ne[i]){
		int v=e[i];
		if(v==fa) continue;
		dfs(v,u);
		if(d[v][0]>=ma){
			ma2=ma;
			ma=d[v][0];
		}else if(d[v][0]>ma2){
			ma2=d[v][0];
		}
	}
	d[u][0]=ma+1;
	d[u][1]=ma+ma2+1;
}

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(h,-1,sizeof h);
		idx=0;
		int ans=0;
		cin>>n>>k;
		for(int i=1,a,b;i<n;i++){
			cin>>a>>b;
			add(a,b),add(b,a);
		}
		if(k==2){
			dfs(1,0);
			for(int i=1;i<=n;i++) ans=max(ans,d[i][1]);
			if(ans&1){
				if((ans/2)&1) cout<<ans/4+1<<"\n";
				else cout<<ans/4<<"\n";
			}else{
				cout<<ans/4<<"\n";
			}
		}else{
			cout<<1<<"\n";
		}
	}
	
	return 0;
}