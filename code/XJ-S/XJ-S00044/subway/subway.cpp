#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int s,t;
int ans1,ans2;
int xb1,xb2;
const int N=1e7+5;
const int INF=1e18;
int in_out[N];
struct Edge{
	int v,w[2];
	int in=0,out=0;
}e1[N],e2[N];

bool find1(int x){//e1

	ans1+=e1[x].w[1];
//	cout<<"x="<<x<<" "<<e1[x].v<<endl;
	x=e1[x].v;
	ans1+=e1[x].w[0];
	if(x==t) return true;
	if(x==0)return false;
}
bool find2(int x){//e2
	ans2+=e2[x].w[1];
//	cout<<"x="<<x<<" "<<e2[x].v<<endl;
	x=e2[x].v;
	ans2+=e2[x].w[0];
	if(x==t) return true;
	if(x==0)return false;
}


signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>in_out[i];
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		int u,ut,v,vt;
		cin>>u>>ut>>v>>vt;
		e1[v].v=u;
		e1[u].out++;
		e1[v].in++;
		e2[u].v=v;
		e2[u].out++;
		e2[v].in++;
		e1[u].w[0]=vt;
		e1[v].w[1]=ut;
		e2[u].w[1]=ut;
		e2[v].w[0]=vt;
	}
//	cout<<"e2"<<endl;
//	for(int i=1;i<=m;i++){
//		cout<<i<<"->"<<e2[i].v<<endl;
//		cout<<e2[i].w[0]<<"  "<<e2[i].w[1]<<endl<<endl;
//	}
//	cout<<"e1"<<endl;
//	for(int i=1;i<=m;i++){
//		cout<<i<<"->"<<e1[i].v<<endl;
//		cout<<e1[i].w[0]<<"  "<<e1[i].w[1]<<endl<<endl;
//	}
	while(q--){
		ans1=0,ans2=0;
		cin>>s>>t;
		bool is_1=find1(s),is_2=find2(s);
//		cout<<(bool)is_1<<" "<<(bool)is_2<<endl;
		if(is_1)cout<<ans1+in_out[s]+in_out[t]<<endl;
		else cout<<ans2+in_out[s]+in_out[t]<<endl;
	}
	return 0;
}
/*
0 2 3 20 2
2 3 4
2 1 2 2 3
2 2 4 3 4
1 3
1 2

*/
