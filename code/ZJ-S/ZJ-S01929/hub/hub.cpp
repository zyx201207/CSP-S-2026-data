#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int c,T;
int n,k,u,v;
int h[N],tot;
struct edge{
	int to,next;
}a[2*N];
void add(int u,int v){
	a[++tot]={v,h[u]};
	h[u]=tot;
}
void init(){
	for(int i=1;i<=n;i++)h[i]=0;
	for(int i=1;i<=tot;i++)a[i]={0,0};
	tot=0;
}
void solve(){
	cin>>n>>k;
	init();
	for(int i=1;i<n;i++){
		cin>>u>>v;
		add(u,v);
		add(v,u);
	}
	if(c==13||c==14){
		int ans=0;
		if(n==k)cout<<"0\n";
		else {
			while(n){
				ans++;
				if(n>k&&n/2<=k){
					cout<<ans<<"\n";
					break;
				}n/=2;
			}
		}
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--)solve();
	return 0;
}/*
0 1
8 7
1 3 5 7 9 11 13 15
*/
