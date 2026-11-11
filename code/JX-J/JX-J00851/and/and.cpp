#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200010],as;
void dfs(int st,int ct,int w){
	if(st==m){
		as=max(as,ct);
		return;
	}
	if(ct<as)return;
	for(int i=w;i<=n;i++){
		dfs(st+1,ct&a[i],i+1);
	}
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,greater<int>());
	if(n<=20){
		dfs(0,(2<<20)-1ll,0);
		cout<<as;
		return 0;
	}
	if(m==1){
		int s=0;
		for(int i=1;i<=n;i++) s=max(s,a[i]);
		cout<<s;
		return 0;
	}
	if(m==2){
		int s=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				s=max(s,(a[i]&a[j]));
			}
		}
		cout<<s;
		return 0;
	}
	if(m==n){
		int s=(2<<20)-1ll;
		for(int i=1;i<=n;i++) s&=a[i];
		cout<<s;
		return 0;
	}
	if(m==n-1){
		int s=(2<<20)-1ll;
		for(int i=1;i<=n;i++){
			int ct=(2<<20)-1ll;
			for(int j=1;j<=n;j++){
				if(j!=i) ct=(ct&a[j]);
			}
			s=max(s,ct);
		}
		cout<<s;
		return 0;
	}
	int tx1=1;
	for(int i=1;i<=n;i++){
		int t=log2(a[i]+1);
		if((2<<t)!=a[i]+1) tx1=0;
		if(!tx1) break;
	}
	if(tx1){
		int s=1e18;
		for(int i=1;i<=n;i++) s=min(s,a[i]);
		cout<<s;
		return 0;
	}
	int s=1e18;
	for(int i=1;i<=n;i++) s=min(s,a[i]);
	cout<<s;
	return 0;
}
