#include<bits/stdc++.h>
using namespace std;
int h[10005],to[10002],val[10005],nxt[10005],cnt;
void build(int u,int v,int w){
	cnt++;
	to[cnt]=v;
	val[cnt]=w;
	nxt[cnt]=h[u];
	h[u]=cnt;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	for(int i=1;i<=T;i++) 
		cout<<pow(2,i)-1<<endl;
	return 0;
} 
