#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;

int G[505][50005];
int c,n,m,d,q;
int w[N];
int k;
int sum=0;
int cot=1e9;
		
struct node{
	int a,t;
}num[N];

struct edge{
	int x,y;
}pl[N];

int kkk;

int pro(int u,int v){
	if (u==v){
		return cot;
	} 
	for (int i=1;i<=k;i++){
		for (int j=1;j<=k;j++){
			kkk=num[j].a;
			if (i==u && kkk!=v){
				cot=min(cot,G[i][num[j].a]);
				pro(num[j].a,v);
			}
		}
	}
	return 0;
}

void solve(){
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}
	for (int i=1;i<=n;i++){
		cin>>k;
		for (int j=1;j<=n;j++){
			for (int z=1;z<=k;z++){
				G[j][k]=-1;
			}
		} 
		for (int j=1;j<=k;j++){
			cin>>num[j].a>>num[j].t;
			G[i][num[j].a]=num[j].t;
		}
	}
	for (int i=1;i<=q;i++){
		cin>>pl[i].x>>pl[i].y;
	}
	for (int i=1;i<=q;i++){
		sum=0;
		sum+=w[pl[i].x]+w[pl[i].y];
		int f=pro(pl[i].x,pl[i].y);
		sum+=f;
		cout<<sum<<"\n"; 
	}
} 

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	solve();
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
