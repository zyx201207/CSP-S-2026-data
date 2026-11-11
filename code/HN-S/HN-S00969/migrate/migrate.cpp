#include<bits/stdc++.h>
#define endl '\n'
#define int long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N=2e6+5,INF=LLONG_MAX;
int c,_,n,k,a[N];
void solB(){
	while(_--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) cin>>a[i];
		int t=0,l=0,r=0;
		for(int i=1;i<=n;i++){
			if(a[i]-a[1]<=k&&a[n]-a[i]<=k){
				t++;
				if(!l) l=i;
				r=i;
			}
		}
		if(t==n){
			cout<<0<<endl;
			continue;
		}
		if(t==2) cout<<(l-1)*(n-r);
		else cout<<0;
		cout<<endl;
	}
}
int mi,t;
void dfs(int i,int st,int sm){
	if(i==st){
		if(sm==mi) t++;
		else if(sm<mi) t=1,mi=sm;
		return ;
	}
	for(int j=i+1;j<=st;j++) if(a[j]-a[i]<=k) dfs(j,st,sm+1);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>c>>_;
	if(c==13||c==14){
		solB();
		return 0;
	}
	while(_--){
		cin>>n>>k;
		int an=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				t=0;
				mi=INF;
				dfs(i,j,0);
				if(t==2) an++;
//				cout<<i<<' '<<j<<' '<<mi<<endl;
			}
		}
		cout<<an<<endl;
	}
	return 0;
}/*
Oct31==Dec25?

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 1
6 4
1 2 4 5 7 8

*/

