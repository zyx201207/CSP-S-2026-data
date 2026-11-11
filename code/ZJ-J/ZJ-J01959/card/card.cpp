#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
int n,m;
const int N=2e5+10;
int c[N];
ll ans[N];
void solve(int i){
//	vector<int> a(n+1);
	vector<int> next(m+2);
//	vector<int> vis(m+1);
//	vector<int> len(m+1);
	for(int j=i-1;j<n;j++){
//		a[j]=c[j];
		next[c[j]]=c[j+1];
	}
	for(int j=i-1;j<n;j++){
		if(next[c[j]]==0)
			break;
		ans[next[c[j]]]++;
	}
	return ;
}
int main(){
	fast;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int T;
	cin>>n>>m;
	T=n;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
//	while(T--){
//		solve(T);
//	}
	for(int i=1;i<=m;i++){
//		cout<<ans[i]<<' ';
		cout<<i<<' ';
	}
	return 0;
}
