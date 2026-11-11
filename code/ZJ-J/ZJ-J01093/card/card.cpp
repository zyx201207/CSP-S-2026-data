#include<bits/stdc++.h>
#define fri freopen("card.in","r",stdin)
#define fro freopen("card.out","w",stdout)
#define con const int
#define endl '\n'
#define int long long
using namespace std;
con N=5e5+5;
int a[N];
int lst[N];
int ans[N];
int last[N];
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		lst[a[i]]=i;
	}
	int r=0;
	for(int i=1;i<=n;i++){
		if(lst[a[i]]>=r){
			ans[a[i]]=0;
			r=lst[a[i]];
		}else{
			ans[a[i]]+=i-last[a[i]]-1;
		}
		last[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		cout<<(lst[i]-ans[i]);
		if(i!=m)cout<<" ";
	}
}
signed main(){
	fri;fro;
	ios::sync_with_stdio(0);
	cin.tie(0);
	int _=1;
//	cin>>_;
	while(_--){
		solve();
	}
	return 0;
}

