#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 200005
struct node{
	int x;char ch;
}a[N];
int n,m;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i].x>>a[i].ch;
		m+=a[i].x;
	}int l=1,r=m,ans=0,u=1,v=n;
	while(l<r&&u<=v){
		const int P=min(a[u].x,a[v].x);
		l+=P;r-=P;
		a[u].x-=P;a[v].x-=P;
		ans+=bool(a[u].ch!=a[v].ch)*P;
		if(a[u].x==0)++u;
		if(a[v].x==0)--v;
	}cout<<ans;
	return 0;
}
