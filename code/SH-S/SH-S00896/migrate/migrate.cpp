#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define FILE(X) freopen(X".in","r",stdin); freopen(X".out","w",stdout);
using namespace std;
const int N=2000060;
int n,d;
int a[N];
int fst[N],lst[N];
int sp_lft[N],sp_rgt[N];
int ans=0;

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	FILE("migrate");
	
	int c,t;
	cin>>c>>t;
	while(t--) {
		cin>>n>>d;
		for(int i=0;i<n;i++) cin>>a[i];
		
		for(int i=0;i<n;i++) fst[i]=lst[i]=sp_lft[i]=sp_rgt[i]=0;
		int hd=0,tl=1;
		for(hd=0;hd<n;hd++) {
			while(tl<n&&a[tl]<=a[hd]+d) tl++;
			if(hd<tl-2) fst[hd]=tl-hd-1,lst[tl-1]=tl-hd-1;
			if(hd==tl-2) sp_lft[hd+1]=sp_lft[hd]+1;
		}
		for(tl=n-1;tl>=0;tl--) {
			while(hd>=0&&a[hd]>=a[tl]-d) hd++;
			if(hd==tl-2) sp_rgt[tl-1]=sp_rgt[hd]+1;
		}
//			for(int i=0;i<n;i++) cout<<fst[i]<<' '; cout<<endl;
//			for(int i=0;i<n;i++) cout<<lst[i]<<' '; cout<<endl;
//			for(int i=0;i<n;i++) cout<<sp_lft[i]<<' '; cout<<endl;
//			for(int i=0;i<n;i++) cout<<sp_rgt[i]<<' '; cout<<endl;
		
		ans=0;
		for(int i=1;i<n-2;i++) {
			if(fst[i]&&lst[i+1]) ans+=(sp_lft[i-1]+1)*(sp_rgt[i+1]+1);
		}
		cout<<ans<<endl;
	}
	return 0;
}

