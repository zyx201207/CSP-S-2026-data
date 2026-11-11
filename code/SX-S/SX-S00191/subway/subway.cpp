#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N1=5e5+5;
const int N2=1e7;
int c,id,n,m,d,q,w[N1],k,x[100005],y[100005];
struct station{
	int a,tr,t,J;
}st[N2];
bool cmp(station x,station y){
	if(x.tr!=y.tr )return x.tr<y.tr;
	else if(x.J!=y.J) return x.J<y.J;
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];//第i号地铁站 口到厅 用时w[i]
	}
	for(int i=1;i<=n;i++){
		cin>>k;//i号线 经过k[i]站
		for(int j=1;j<=k;j++){
			cin>>st[++id].a>>st[id].t;
			//i号线会经过的第j站为a号站
			//i号线在第j站（a号站）站台到站厅用时t
			st[id].tr=i;
			st[id].J=j;
		}
	}
	sort(st+1,st+1+id,cmp);
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	int q1=q;
	while(q1--){
		int r=q-q1;
		int sum=0;
		sum+=w[x[r]]+w[y[r]];
		cout<<sum;
	}
	return 0;
}