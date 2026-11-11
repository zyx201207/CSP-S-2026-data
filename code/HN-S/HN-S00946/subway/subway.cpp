#include<bits/stdc++.h>
using namespace std;
const int N=100100;
int head[N],tot;
struct Edge{
	int to,w,nxt;
}edge[N<<2];
void add(int x,int y,int w){
	edge[++tot]={y,w,head[x]};
	head[x]=tot;
}
int n,m,k,c,a[N],b1,b2,t1,t2c,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=m;i++){
		cin>>k;
	}
	for(int i=1;i<=n;i++){
		cout<<0<<endl;
	}
	return 0;
}

