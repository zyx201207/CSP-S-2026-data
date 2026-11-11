#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[2000009],ne[2000009],la[2000009],dl[2000009],dr[2000009],n,d,fl[2000009];
vector<int> une[2000009],ula[2000009];
inline int que(int x){
	if(x<a[1]) return 0;
	int l=1,r=n;
	while(l<r){
		int mid=l+(r-l+1)/2;
		if(a[mid]<=x) l=mid;
		else r=mid-1;
	}
	return l;
}
inline void solve(){
	
	cin>>n>>d;
	for(int i=0;i<=n+1;i++) a[i]=ne[i]=la[i]=dl[i]=dr[i]=0,une[i].clear(),ula[i].clear(),fl[i]=0;
	for(int i=1;i<=n;i++) cin>>a[i];a[0]=-4e18,a[n+1]=4e18;
	for(int i=1;i<=n;i++){
		int l=i,r=n;
		while(l<r){
			int mid=(l+r+1)/2;
			if(a[mid]-a[i]<=d) l=mid;
			else r=mid-1;
		}
		ne[i]=l;
		l=1,r=i;
		while(l<r){
			int mid=(l+r)/2;
			if(a[i]-a[mid]<=d) r=mid;
			else l=mid+1;
		}
		la[i]=l;
		une[ne[i]].push_back(i);ula[la[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){dl[i]=1;
		for(int y:une[i]){
			if(y==i) continue;
			if(la[i]==y) dl[i]+=dl[y];
			else dl[i]++;
		}
	}
	for(int i=n;i>=1;i--){dr[i]=1;
		for(int y:ula[i]){
			if(y==i) continue;
			if(ne[i]==y) dr[i]+=dr[y];
			else dr[i]++;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(ne[i]==i) continue;
		int x=ne[i];
		if(ne[x]!=x){
			int y=ne[x];
			if(la[la[y]]==i&&x-la[y]==1){
				ans=(ans+dl[i]*dr[y]-1);
			}
			else if(x-la[y]==1){
				ans=(ans+dr[y]-1);
			}
		}
		if(x!=i+1)ans=(ans+que(a[x-1]+d)-que(a[x-2]+d));
	}
//	cout<<ans<<'\n';
	for(int i=1;i<=n;i++){
		if(la[i]==i) continue;
		int x=la[i];
		if(la[x]!=x){
			int y=la[x];
			if(ne[ne[y]]!=i&&ne[y]-x==1){
				ans=(ans+dl[y]-1);
			}
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c;cin>>c;
	int _=1;cin>>_;
	while(_--) solve();
	return 0;
}
