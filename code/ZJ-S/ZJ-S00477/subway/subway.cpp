#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[1100],zz[1100],j[510000];
vector<int>a[1100],t[510000],z[510000];
struct p{
	int v,s;
};
vector<p>b[510000];
queue<int>qq;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>zz[i];
		for(int i2=1;i2<=zz[i];i2++){
			int x,y;
			cin>>x;
			a[i].push_back(x);
			cin>>y;
			t[i].push_back(y);
		}
	}
	for(int i=1;i<=n;i++){
		for(int i2=0;i2<zz[i];i2++){
			for(int i3=i2+1;i3<zz[i];i3++){
//				cout<<i<<" "<<i2<<" "<<i3<<"\n";
				p X;
				X.v=a[i][i3],X.s=t[i][i2]+t[i][i3];
//				cout<<a[i][i2]<<"->"<<a[i][i3]<<":"<<t[i][i2]<<"+"<<t[i][i3]<<"\n";
				b[a[i][i2]].push_back(X);
			}
		}
	}
//	cout<<"jbwc!\n";
	while(q--){
		int x,y;
		cin>>x>>y;
		int S=0;
		S+=w[x]+w[y];
		for(int i=0;i<=m+1;i++)j[i]=-1;
		j[x]=0;
		while(!qq.empty())qq.pop();
		qq.push(x);
		while(!qq.empty()){
			int xx=qq.front();
//			cout<<xx<<"!!!\n";
			qq.pop();
			for(int i=0;i<b[xx].size();i++){
				int yy=b[xx][i].v;
//				cout<<xx<<"->"<<yy<<":"<<b[xx][i].s<<"?\n";
				if(j[yy]>j[xx]+b[xx][i].s||j[yy]==-1){
//					cout<<x<<"->"<<xx<<"->"<<yy<<"="<<j[xx]+b[xx][i].s<<"<"<<x<<"->"<<yy<<"\n";
					j[yy]=j[xx]+b[xx][i].s;
					qq.push(yy);
				}
			}
		}
		cout<<S+j[y]<<"\n";
	}
	return 0;
}
