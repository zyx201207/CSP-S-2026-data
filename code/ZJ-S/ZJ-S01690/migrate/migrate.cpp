#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int n,d,a[N];
int tl[N],tr[N],f[N],g[N];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i],f[i]=g[i]=0;
	for(int i=1,j=1;i<=n;i++){
		while(j<n && a[j+1]-a[i]<=d) j++;
		tr[i]=j;
	}
	for(int i=n,j=n;i>=1;i--){
		while(j>1 && a[i]-a[j-1]<=d) j--;
		tl[i]=j;
	}
	for(int i=1;i<=n;i++){
		if(tl[i]<i && i<=tr[tl[i]]) g[tl[i]]++;
		if(tr[i]>i && i>=tl[tr[i]]) f[tr[i]]++;
	}
	for(int i=1;i<=n;i++){
		if(tl[i]<i && tr[tl[i]]==i) f[i]+=f[tl[i]];
	}
	for(int i=n;i>=1;i--){
		if(tr[i]>i && tl[tr[i]]==i) g[i]+=g[tr[i]];
	}
//	for(int i=1;i<=n;i++){
//		cerr<<f[i]<<" "<<g[i]<<"\n";
//	}
	int ans=0;
	for(int i=1;i<n;i++){
//		for(int l=tl[i+1];l<i;l++){
//			for(int r=i+2;r<=tr[i];r++){
//				if(tr[l]<r && tl[r]==i && tr[l]==i+1){
////					cerr<<i<<" "<<l<<" "<<r<<"\n";
//					ans++;
////					if(tr[i+1]==r){
//						ans+=g[r];
////					}
////					if(tl[i]==l){
//						ans+=f[l];
////					}
////					if(tr[i+1]==r && tl[i]==l){
//						ans+=f[l]*g[r];
////					}
//				}
//			}
//		}
		if(tr[i]>i+1 && tl[i+1]<i) ans+=f[i+1]*g[i];
	}
	cout<<min(ans,n*(n-1)/2)<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--) solve();
	return 0;
}
/*
0 1
10 22
0 7 14 21 28 35 42 49 56 63
*/
/*
0 1
6 4
-3 0 1 2 3 4
*/