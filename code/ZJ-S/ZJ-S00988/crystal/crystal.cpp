#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N=1e6+5;
int n,a[N],ans,m,s[N],maxn;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int l=1,r=1;
	while(1){
		bool flag=0;
		while(r<=n&&a[r]*(r-l+1)<=m+(s[r]-s[l-1])){
			maxn=max(maxn,r-l+1);
			r++;flag=1;
		}
		while(l<=r&&a[r]*(r-l+1)>m+(s[r]-s[l-1])){
			l++;flag=1;
		}
		if(!flag)break;
	}
	cout<<maxn<<'\n';
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--)solve();
	return 0;
}
