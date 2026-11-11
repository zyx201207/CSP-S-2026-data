#include<bits/stdc++.h>
using namespace std;
struct node{
	int id,t;
};
const int N=5e5+10;
int c,n,m,w[N],k[510],floy[510][510],q,d,v;
vector<node>e[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>v;
			node x;
			x.id=i;
			cin>>x.t;
			e[v].push_back(x);
		}
	}
	memset(floy,0x3f,sizeof(floy) );
	for(int i=1;i<=n;i++)floy[i][i]=0;
	for(int i=1;i<=m;i++){
		for(auto j:e[i])
			for(auto s:e[i]){
				int f=j.t+s.t;
				floy[j.id][s.id]=min(floy[j.id][s.id],f);
			}
	}
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
		floy[i][j]=min(floy[i][k]+floy[k][j],floy[i][j]);
	while(q--){
		int A,B,ans=0x3f3f3f3f;cin>>A>>B;
		for(auto i:e[A])for(auto j:e[B]){
			ans=min(ans,floy[i.id][j.id]+i.t+j.t);
		}
		cout<<ans+w[A]+w[B]<<"\n";
	}
	return 0;
}
