#include<bits/stdc++.h>
using namespace std;
//const int N=1e6+10;
int u,v;
struct Node{
	int next[110];
}nd[1000010];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0); 
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1,cnt=0;i<n;i++){
			cin>>u>>v;
			nd[u].next[++cnt]=v;
			nd[v].next[cnt]=u;
		}
		if(k*2+1>=n)cout<<1<<endl;
		else cout<<2<<endl;
	}
	return 0;
} 