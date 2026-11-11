#include<bits/stdc++.h>
using namespace std;
struct node{
	int to,sum;
};
int c,n,m,dd,q;
int a[1510];
int d[1510][1510];
bool kk[1510];
vector<node> e[500550];
void Litter_road(int start,int now){
	for(int i=0;i<(int)e[now].size();i++){
		int to=e[now][i].to;
		if(kk[to]==1) continue;
		int sum=e[now][i].sum;
		if(d[start][to]>d[start][now]+sum)
			d[start][to]=d[start][now]+sum;
		kk[to]=1;
		Litter_road(start,to);
		kk[to]=0;
	}
}
void work1(){
	cin>>n>>m>>dd>>q;
	for(int i=1;i<=m;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			e[x].push_back({i+m,y});
			e[i+m].push_back({x,y});
		}
	}
	memset(d,63,sizeof(d));
	for(int i=1;i<=m;i++)
		d[i][i]=0;
	for(int i=1;i<=m;i++)
		Litter_road(i,i);
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int t=d[x][y];
		t+=a[x];
		t+=a[y];
		cout<<t<<endl;
	}
}
int pre[5000010];
void work2(){
	cin>>n>>m>>dd>>q;
	if(n==1){
		for(int i=1;i<=m;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			for(int j=1;j<=k;j++){
				int x,y;
				cin>>x>>y;
				pre[x]=y;
			}
		}
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			cout<<a[x]+pre[x]+pre[y]+a[y]<<endl;
		}
		return ;
	}
	else{
		cin>>n>>m>>dd>>q;
		for(int i=1;i<=m;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			for(int j=1;j<=k;j++){
				int x,y;
				cin>>x>>y;
				e[x].push_back({i+m,y});
				e[i+m].push_back({x,y});
			}
		}
		memset(d,63,sizeof(d));
		for(int i=1;i<=m;i++)
			d[i][i]=0;
		for(int i=1;i<=m;i++)
			Litter_road(i,i);
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			int t=d[x][y];
			t+=a[x];
			t+=a[y];
			cout<<t<<endl;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c;
	if(c<=19){
		work1();
		return 0;
	}
	else{
		work2();
		return 0;
	}
}
