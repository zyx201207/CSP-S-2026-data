#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int c,t;
int n,d,x[N];
int f[N],g[N],cnt[N];
int pre[N],nxt[N],ll[N],rr[N],pl[N],pr[N];
int cntl[N],cntr[N];
inline void MAIN(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	
	if(c<=10){
		int ans=0;
		for(int l=1;l<=n;l++){
			//cout<<"l = "<<l<<'\n';
			for(int i=1;i<=n;i++) f[i]=0,g[i]=0,cnt[i]=0;
			g[l]=1;cnt[0]=1;
			int lst=l,tot=1;
			for(int i=l+1;i<=n;i++){
				if(x[i]-x[i-1]>d) break;
				while(x[i]-x[lst]>d){
					tot-=g[lst];
					++lst;
					if(tot==0) tot=cnt[f[lst]];
				}
				f[i]=f[lst]+1,g[i]=tot;cnt[f[i]]+=g[i];
				//cout<<"    i = "<<i<<" lst = "<<lst<<" tot = "<<tot<<" f[i] = "<<f[i]<<'\n';
				if(g[i]==2) ans++;
			}	
		}
		cout<<ans<<'\n';
		return;
	}
	
	
	if(c>=11&&c<=12){
		if(n==1){
			cout<<"0\n";
			return;
		}
		int k=x[2]-x[1];
		if(k>=d){
			cout<<"0\n";
			return;
		}
		int p=d/k;
		cout<<max(0ll,n-2*p+1)<<'\n';
		return;
	}
	/*
	int l=n,r=1;
	for(int i=1;i<=n;i++){
		if(x[i]-x[1]<=d&&x[n]-x[i]<=d) l=min(l,i),r=max(r,i);
	}
	*/
	for(int i=1;i<=n;i++) ll[i]=rr[i]=pl[i]=pr[i]=0;
	for(int l=1,r=1;l<=n;l++){
		while(r+1<=n&&x[r+1]-x[l]<=d) ++r;
		nxt[l]=r;ll[r]++;if(pl[r]==0) pl[r]=l;
	}
	for(int r=n,l=n;r>=1;r--){
		while(l-1>=1&&x[r]-x[l-1]<=d) --l;
		pre[r]=l,rr[l]++;if(pr[l]==0) pr[l]=r;
	}
	for(int i=1;i<=n;i++) cntl[i]=cntr[i]=1;
	for(int i=1;i<=n;i++){
		if(nxt[i]!=i) cntl[nxt[i]]+=cntl[i];
	} 
	for(int i=n;i>=1;i--){
		if(pre[i]!=i) cntr[pre[i]]+=cntr[i];
	}
	
//	for(int i=1;i<=n;i++) cout<<nxt[i]<<" ";
//	cout<<'\n';
//	for(int i=1;i<=n;i++) cout<<pre[i]<<" ";
//	cout<<'\n';
//	for(int i=1;i<=n;i++) cout<<ll[i]<<" ";
//	cout<<'\n';
//	for(int i=1;i<=n;i++) cout<<rr[i]<<" ";
//	cout<<'\n';
//	for(int i=1;i<=n;i++) cout<<cntl[i]<<" ";
//	cout<<'\n';
//	for(int i=1;i<=n;i++) cout<<cntr[i]<<" ";
//	cout<<'\n';
	
	
	
	int ans=0;
	for(int i=1;i<=n;i++){
		if(x[i]-x[i-1]>d) continue;
		int lll=ll[i]-(nxt[i-1]==i)-(nxt[i]==i),rrr=rr[i-1]-(pre[i]==i-1)-(pre[i-1]==i-1);
		//if(lll==1&&rrr==1) ans+=cntl[pl[i]]*cntr[pr[i-1]];
		if(lll==1) lll=cntl[pl[i]];
		if(rrr==1) rrr=cntr[pr[i-1]];
		//cout<<"i = "<<i<<" "<<lll<<" "<<rrr<<'\n';
		ans+=lll*rrr;
		
	}
	cout<<ans<<'\n';
	return;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--) MAIN();
	return 0;
}
