#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+10;
ll xx[N];
int r[N],l[N],pre[N],suf[N],n;
int l1[N],l2[N],r1[N],r2[N];
int le(int l,int r,int x){
	if(x<1||x>n||l>r) return 0;
	return max(0,min(r,l2[x])-max(l,l1[x])+1);
}
int ri(int l,int r,int x){
	if(x<1||x>n||l>r) return 0;
	return max(0,min(r,r2[x])-max(l,r1[x])+1);
}
void solve(){
	ll d;cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>xx[i];
	for(int i=1;i<=n;i++){
		r[i]=r[i-1];
		while(r[i]<n&&xx[r[i]+1]-xx[i]<=d) r[i]++;
	}
	for(int i=n;i;i--){
		l[i]=(i<n?l[i+1]:n);
		while(l[i]>1&&xx[i]-xx[l[i]-1]<=d) l[i]--;
	}
	for(int i=1;i<=n;i++) l1[i]=l2[i]=r1[i]=r2[i]=0;
	for(int i=1;i<=n;i++){
		if(!l1[l[i]]) l1[l[i]]=i;
		l2[l[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(!r1[r[i]]) r1[r[i]]=i;
		r2[r[i]]=i;
	}
	ll ans=0;
	for(int i=n;i;i--){
		suf[i]=1;
		if(r[i]>i){
			suf[i]+=le(i+1,r[i]-1,i);
			//for(int j=i+1;j<r[i];j++) suf[i]+=(l[j]==i);
			if(l[r[i]]==i) suf[i]+=suf[r[i]];
		}
	}
	for(int i=1;i<=n;i++){
		pre[i]=1;
		if(l[i]<i){
			pre[i]+=ri(l[i]+1,i-1,i);
			//for(int j=l[i]+1;j<i;j++) pre[i]+=(r[j]==i);
			if(r[l[i]]==i) pre[i]+=pre[l[i]];
		}
	}
	//for(int i=1;i<=n;i++) cerr<<l[i]<<" "<<r[i]<<"\n";
	for(int i=2;i<=n;i++){
		int cr=le(i+1,r[i]-1,i-1),cl=ri(l[i-1]+1,i-2,i);
		//for(int j=i+1;j<r[i];j++) cr+=(l[j]==i-1);
		if(r[i]>i&&l[r[i]]==i-1) cr+=suf[r[i]];
		//for(int j=l[i-1]+1;j<i-1;j++) cl+=(r[j]==i);
		if(l[i-1]<i-1&&r[l[i-1]]==i) cl+=pre[l[i-1]];
		ans+=1ll*cl*cr;
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(0);
	int cid,T;cin>>cid>>T;
	while(T--) solve();
	return 0;
}