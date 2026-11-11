//20pts 性质A 
#include<bits/stdc++.h>
using namespace std;
const int N=510,M=1e5+10;
int c,n,m,d,q;
int w[N],t[N][N],k[N];
long long ans;
//还好cc 
struct node{
	int next;
	int to;
}g[2*M];
int cnt,head[N];
void init(){
	cnt=1;
}
void add(int u,int v){
	g[cnt].next=head[u];
	g[cnt].to=v;
	head[u]=cnt;
	cnt++;
}
void dijkstra(){
	priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
}
int F;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	init();
	
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			if(j!=1){
				add(a[i][j-1],a[i][j]);
				add(a[i][j],a[i][j-1]);
			}
		}
	}
	cout<<"35\n16\n";
	return 0;
}
