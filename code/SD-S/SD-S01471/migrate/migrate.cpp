#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve();
main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}
}
int x[2014514];
int lst[2014514],nxt[2014514];
int bac[2014514],frt[2014514];
void solve(){
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	//remind nxt[i]=i !
	int l=1,r=1;
	x[n+1]=9e18;
	for(;l<=n;l++){
		while(x[r+1]-x[l]<=d&&r<n)r++;
		nxt[l]=r;
	}
	x[0]=-9e18;
	l=n,r=n;
	for(;r>=1;r--){
		while(x[r]-x[l-1]<=d&&l>1)l--;
		lst[r]=l;
	}
	for(int i=1;i<=n;i++){
		if(nxt[lst[i]]==i&&lst[i]!=i){
			frt[i]=frt[lst[i]]+1; 
		}
		else{
			frt[i]=0;
		}
	}
	for(int i=n;i>=1;i--){
		if(lst[nxt[i]]==i&&nxt[i]!=i){
			bac[i]=bac[nxt[i]]+1;
		}
		else{
			bac[i]=0;
		}
	}
	int ans=0;
//	for(int i=1;i<=n;i++){
//		int l=nxt[i];
//		int l2=nxt[l];
//		if(l==l2||l==i)continue;
//		cout<<i<<" "<<l<<" "<<l2<<endl;
//		if(x[l2-1]-x[l-1]<=d&&x[l2-1]-x[l-2]>d){
//			ans+=(frt[i]+1)*(bac[l2-1]+1);
//		}
//		else if(x[l2]-x[l-1]<=d&&x[l2]-x[l-2]>d){
//			ans+=(frt[i]+1)*(bac[l2]+1);
//		}
//	}
	l=1,r=1;
//	for(int i=1;i<=n;i++)cout<<lst[i]<<" ";cout<<endl;
//	for(int i=1;i<=n;i++)cout<<nxt[i]<<" ";cout<<endl;
	for(;l<=n;l++){
		if(r<n&&(x[r]-x[l]<=d||lst[r+1]+1<=nxt[l])){
			while(r<n&&(x[r]-x[l]<=d||lst[r]+1<nxt[l])){
				r++;
				if(lst[r]+1==nxt[l]&&x[r]-x[l]>d){
					int x=(frt[l]+1);
					int y=(bac[r]+1);
					if(lst[lst[r]]!=l)x=1;
					if(nxt[nxt[l]]!=r)y=1;
					ans+=x*y;
	//				cout<<l<<" "<<r<<" "<<frt[l]<<" "<<bac[r]<<" "<<x<<" "<<y<<endl;
				}
//				cout<<l<<" "<<r<<endl;
			}
		}
		else if(lst[r]+1==nxt[l]&&x[r]-x[l]>d){
			int x=(frt[l]+1);
			int y=(bac[r]+1);
			if(lst[lst[r]]!=l)x=1;
			if(nxt[nxt[l]]!=r)y=1;
			ans+=x*y;
//			cout<<l<<" "<<r<<" "<<frt[l]<<" "<<bac[r]<<" "<<x<<" "<<y<<endl;
		}
//		cout<<l<<" "<<r<<endl;
	}
	cout<<ans<<'\n'; 
}
// I'm sure I've found the right solution
// But how so many corner cases???
// hopes 100 pts.
