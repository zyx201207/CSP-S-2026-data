#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int xx[MAXN];
long long dp[MAXN];
int N;
long long D;
int lft[MAXN],rgt[MAXN];
int mxl[MAXN],mxr[MAXN];
long long dpo[MAXN];
void solve(){
	memset(mxl,0x3f,sizeof(mxl));
	cin>>N>>D; 
	for(int i=1;i<=N;i++) cin>>xx[i];
	for(int l=1,r=1;l<=N;l++){
		while(r<=N&&xx[r]-xx[l]<=D) r++;
		mxr[l]=r-1;
		mxl[r-1]=std::min(r-1,l);
	}
	for(int i=1;i<N;i++){
		dpo[i]+=i-mxl[i];
		int l=mxl[i],r=mxr[i+1];
		if(mxl[i+1]!=l) continue;
		if(mxr[i]!=r) continue;
		if(i-1>0&&xx[r]-xx[i-1]<=D) continue;
		if(i+2<=N&&xx[i+2]-xx[l]<=D) continue;
		lft[i]=true;
		rgt[i+1]=true;
		if(!lft[l]&&!rgt[l]) dp[r]+=dpo[l];
		if(!lft[l]&&!rgt[l]) dpo[i]+=dpo[l];
//		if(!lft[l]&&!rgt[l]) dpo[i+1]+=dpo[l];
	}
	long long ans=0;
	for(int i=1;i<=N;i++){
		ans+=dp[i];
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	
	
	return 0;
}
