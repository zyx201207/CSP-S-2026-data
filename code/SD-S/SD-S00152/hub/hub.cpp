#include<bits/std++.h>
using namespace std;
typedef long long ll;
const int N=100005;
const ll lNF=0x3f3f3f3f3f3f3f3f;

int main(){
	freopen("hub.in"."r".stdin);
	freopen("hub.out"."w".stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int c;
	int n,k;
	ve<int> tr[1000005];
	int dis[4005][4005];
	void get(int x,int fa,int tr){
	    for (auto y:tr[x]){
	    	if (y==fa)continue;
	    	dis[tr][y]=dis[tr][x]+1;
	    	get (y,x,rt);
		}
	}
	void solve(){
		cin>>n>>k;
		for(int i=1;i<=n;i++) tr(i).clear();
		for(int i=1;i<=n;i++){
			int x,y;
			cin>>x>>y;
			tr[x].pb(y);
			tr[y].pb(x);
			
		}
		if(c<=6){
			for(int i=1;i<=n,i++){
				tmp[i]=f[x][i];
			}
		}
		
		}
		}
	}
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++);
	{
		cin>>w[j];
	}
	for(int i=1;i<=n;i++);
	{
		cin>>k[i];
		for(int j=1;j<=k;j++);
		{
			cin>>a[j]>>t[j];
		}
		for(int p=j;p<=k;p++);
		{
			v[a[j]][a[p]]=0;
			}	
}
	return 0;
	
}
	
