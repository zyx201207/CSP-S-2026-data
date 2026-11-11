#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,m;
const int nn=5e5+5;
int prv[nn];
int a[nn];
inline bool check(int l,int r){
	int gs=r-l+1;
	return a[r]*gs-(prv[r]-prv[l-1])<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		prv[i]=prv[i-1]+a[i];
	}
	int it=1,res=0;
	for(int i=1;i<=n;i++){
		while(!check(it,i)) it++;
		res=max(res,i-it+1);
	}
	cout<<res<<"\n";
	return 0;
}