#include<bits/stdc++.h>
using namespace std;
struct dot{
	int d,l;
};
struct sid{
	int d,l,v;
};
struct node{
	dot ne;
	vector<sid> v;
}t[510][50010];
int c,n,m,d,q,w[500010],k,a[510][500010],ti[510][500010],s,l,vis[500010],sh[500010];
void fi(int x,int y,int e,int p){
	for(int i=0;i<int(t[y][x].v.size());i++){
		if(p+t[y][x].v[i].v<sh[t[y][x].v[i].d]&&!vis[t[y][x].v[i].d]){
			sh[t[y][x].v[i].d]=p+t[y][x].v[i].v;
			vis[t[y][x].v[i].d]=1;
			fi(t[y][x].v[i].d,t[y][x].v[i].l,e,p+t[y][x].v[i].v);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		cin>>a[i][1]>>ti[i][1];
		for(int j=2;j<=k;j++){
			cin>>a[i][j]>>ti[i][j];
			t[i][a[i][j]].ne={a[i][j],i};
			t[i][a[i][j]].v.push_back({a[i][j-1],i,0});
			t[i][a[i][j-1]].v.push_back({a[i][j],i,0});
		}
		for(int j=1;j<=n;j++){
			for(int o=1;o<=k;o++){
				if(t[j][a[i][o]].ne.d!=0){
					t[j][a[i][o]].v.push_back({a[i][j],i,ti[i][j]+ti[j][a[i][o]]});
					t[i][a[i][o]].v.push_back({a[j][o],j,ti[i][j]+ti[j][a[i][o]]});
				}
			}
		}
	}
	while(q--){
		memset(vis,0,sizeof(vis));
		memset(sh,0x3f,sizeof(sh));
		cin>>s>>l;
		fi(s,0,l,0);
		cout<<sh[l]+w[s]+w[l]<<"\n";
	}
	return 0;
}
