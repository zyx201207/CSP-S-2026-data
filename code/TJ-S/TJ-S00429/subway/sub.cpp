#include<iostream>//RP++
#include<vector>
using namespace std;
long long c,n,m,d,q;
struct node{
	int de,di;
}nd;
vector<node> dis[500005];
int u,v,w[500005],k[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	if(c>=7&&c<=11){
		for(int i=1;i<=m;i++) cin>>w[i];
		for(int i=1;i<=n;i++){
			cin>>k[i];
			if(k[i]==1) cin>>u;
			else{
				cin>>u>>v;
				
			}
		}
	}
	
	
	return 0;
} 
