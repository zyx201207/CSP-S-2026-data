#include<bits/stdc++.h>
using namespace std;
#define lint long long
struct node{
	lint e;
	lint z;
};
lint c,n,m,d,q,a[505];
vector<node> tu[505];
bool yo[505];
lint vis[505][505];
void dij(lint x){
//	cout<<x<<endl;
	for(int i=1;i<=m;i++){
		vis[x][i]=1e8;
		yo[i]=0;
	}
	vis[x][x]=0;
	lint cnt=0;
	while(cnt<=m){
	//	cout<<cnt<<endl;
		lint st=0;
		for(int i=1;i<=m;i++){
			if((st==0 || vis[x][st]>vis[x][i]) && yo[i]==0){
				st=i;
			}
		}
		yo[st]=1;
		cnt++;
		for(lint i=0;i<tu[st].size();i++){
			lint k,l;
			k=tu[st][i].e;
			l=tu[st][i].z;
			if(vis[x][k]>vis[x][st]+l){
				vis[x][k]=vis[x][st]+l;
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(lint i=1;i<=n;i++){
		lint k,x,y,z,p;
		cin>>k>>x>>y>>z>>p;
		z+=p;
		tu[x].push_back({y,z});
		tu[y].push_back({x,z});
	}
	for(lint i=1;i<=m;i++){
		dij(i);
	}
	for(int i=1;i<=q;i++){
		lint x,y;
		cin>>x>>y;
		cout<<vis[x][y]+a[x]+a[y]<<endl;
	}
	return 0;
} 
