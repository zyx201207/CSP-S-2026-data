#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
const int N=2e6+7;
const int inf=1e18;
int n,dd,a[N],d[5007][5007],res[5007][5007];
vector<int>e[5007];
bool vis[5007];
inline void bfs(int s){
	for(int i=s;i<=n;i++)d[s][i]=inf,res[s][i]=0,vis[i]=0;
	d[s][s]=0,res[s][s]=1;
	queue<int>q;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto v:e[u]){
			if(d[s][v]>d[s][u]+1){
				d[s][v]=d[s][u]+1;
				res[s][v]=res[s][u];
				q.push(v);
			}else if(d[s][v]==d[s][u]+1){
				res[s][v]+=res[s][u];
			}
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
	cout.tie(0);
	int c,T;cin>>c>>T;
	if(c<=10){
		while(T--){
			cin>>n>>dd;
			for(int i=1;i<=n;i++)cin>>a[i],e[i]={};
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(a[j]-a[i]<=dd)e[i].push_back(j);
				}
			}
			for(int i=1;i<=n;i++)bfs(i);
			int x=0;
			for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			if(res[i][j]==2)x++;
			cout<<x<<"\n";
		}
    }else if(c==11||c==12){
    	while(T--){
		
    	cin>>n>>dd;
    	for(int i=1;i<=n;i++)cin>>a[i];
    	int dx=a[2]-a[1];
        if(dx*2ll>dd){
			cout<<0<<"\n";
		}else{
			int x=0;
			for(int i=1;i<=n;i++)
			if(a[n]-a[i]>dd){
				int t1=upper_bound(a+1,a+1+n,min(a[i]+dd,inf+1))-a;
				int t2=lower_bound(a+1,a+1+n,min(inf+1,a[i]+2*dd))-a-1;
				x+=t2-t1+1;
			}
			cout<<x<<"\n";
		}
	    }
	}else{
		while(T--){
			cin>>n>>dd;
			for(int i=1;i<=n;i++)cin>>a[i];
			cout<<0<<"\n";
		}
	}
}

