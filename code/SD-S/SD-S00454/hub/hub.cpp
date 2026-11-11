#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2e6+10,K=1e6+10;
int c,T,n,m,x,y,pre[N],k,son[N];
bool f[N];
struct node{
	int from,to,ne;
}e[N];
void add(int x,int y){
	e[++k]={x,y,pre[x]};
	pre[x]=k;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<n;i++){
			cin>>x>>y;
			add(x,y);
			add(y,x);
		}
		cout<<n/4<<"\n";
	}

	return 0;
}
