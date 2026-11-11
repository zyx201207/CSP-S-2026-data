#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N];
int t[N],tp;
int n,m;
int vis[N];
int ans[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
//	for(int i=n;i>=0;i--) cerr<<a[i]<<" ";
	for(int i=n;i>=1;i--){
		if(vis[a[i]]!=0){
			for(int j=vis[a[i]]+1;j<=tp;j++){
				vis[t[j]]=0;
			}
			tp=vis[a[i]]-1;
		}
		tp++;
//		cerr<<"------------------"<<tp<<"---------------------\n";
		t[tp]=a[i];
		vis[a[i]]=tp;
		for(int i=1;i<=tp;i++){
			ans[t[i]]++;
//			cerr<<t[i]<<" ";
		}
//		cerr<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/
