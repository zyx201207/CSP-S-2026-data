#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=1e6;
struct Edge{
	int u,v,next;
}e[MAXN];
int head[MAXN];
int cnt;
void add(int u,int v){
	e[cnt].u=u;
	e[cnt].v=v;
	e[cnt].next=head[u];
	head[u]=cnt++;
}
int c,t,n,k;

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	return 0;
}

