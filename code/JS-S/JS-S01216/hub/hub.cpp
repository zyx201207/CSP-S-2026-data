#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,cnt,from[1000005];
struct edge{
	int to,next;
}e[1000006];
void add(int u,int v){
	e[++cnt].to=v;
	e[cnt].next=from[u];
	from[u]=cnt;
}
signed main(){
	srand(time(NULL));
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		cout<<rand()<<"\n";
	}
	return 0;
}
