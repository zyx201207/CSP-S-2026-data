#include<bits/stdc++.h>
using namespace std;
struct info{
	int a,t;
};
int c,n,m,d,q;
int w[500005];
int k[500005];
vector<info> in[500005];

int guess(int x,int y){
	int cnt=0; 
	cnt+=w[x];
	cnt+=w[y];
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a,t;
			cin>>a>>t;
			in[i].push_back({a,t});
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<guess(x,y)<<"\n";
	}
}