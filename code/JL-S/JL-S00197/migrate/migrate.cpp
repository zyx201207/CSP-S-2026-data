#include<bits/stdc++.h>
#define endl '\n'
#define int long long 
using namespace std;

int ds[2000006];
int c,t,n,d;
struct node{
	int u,w;
	bool operator>(node x)const{
		return w>x.w;
	}
};
//vector<int> line[505];

int dij(int st,int ed){
	int dist[200006];
	priority_queue<node,vector<node>,greater<node> > q;
	memset(dist,0x3f,sizeof dist);
	q.push({st,0});
	dist[st]=0;
	int res=0;
	while(!q.empty()){
		if(res>2){break;}
		node ft=q.top();
		int u=ft.u;
		int w=ft.w;
		q.pop();
		if(dist[u]<w) continue;
		if(u==ed){
			cout<<st<<' '<<ed<<' '<<dist[u]<<'\n';
			dist[u]=w;
			res++;
			continue;
		}
		for(int i=u+1;i<=n;i++){
			if(abs(ds[i]-ds[u])<=d){
				if(dist[i]>=dist[u]+abs(ds[i]-ds[u])){
					dist[i]=dist[u]+abs(ds[i]-ds[u]);
					q.push({i,dist[i]});
				}
			}
			else{
				break;}
		}
		for(int i=u-1;i>=1;i--){
			if(abs(ds[i]-ds[u])<=d){
				if(dist[i]>=dist[u]+abs(ds[i]-ds[u])){
					dist[i]=dist[u]+abs(ds[i]-ds[u]);
					q.push({i,dist[i]});
				}
			}
			else{
				break;
				
			}
		}
		
	}
	
	
		
	return res;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>ds[i];
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				if(dij(i,j)==2) {
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
/*0 2 5 20 2
 4 1 9 2 5
 3 1 5 2 7 4 6
 3 2 3 3 4 5 7
 1 3
 1 2
*/
/*0 2
4 2
1 2 3 4
5 2
1 2 3 4 5*/

