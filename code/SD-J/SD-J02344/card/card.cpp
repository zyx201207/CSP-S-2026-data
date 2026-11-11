#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,k[N],m,cnt[N],a[N],len,jk[N],kj;
bool vis[N];
void mem(int x){
	for(int i=len;i>=1;i--){
		if(a[i]!=x) vis[a[i]]=0;
		else{
			len=i-1;
			return;
		}
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>k[i];
	if(n>10000){
		bool flag1=1,flag2=1;
		for(int i=1;i<n;i++){
			if(a[i+1]>a[i]) flag1=0;
			if(a[i]==a[i+1]) flag2=0;
		}
		kj=m;
		if(flag1){
			for(int i=n;i>=1;i--){
				if(k[i]==kj) jk[kj]=i,kj--;
			}
			for(int i=1;i<=m;i++) cout<<jk[i]<<" ";
		}else if(flag2){
			for(int i=1;i<=n;i++) jk[k[i]]=i;
			for(int i=1;i<=m;i++) cout<<jk[i]<<" ";
		}
		return 0;
	}
	for(int nn=1;nn<=n;nn++){
		len=0;
		memset(a,0,sizeof a);
		for(int i=nn;i<=n;i++){
			if(vis[k[i]]) mem(k[i]);
			vis[k[i]]=true;
			a[++len]=k[i];
		}
		for(int i=1;i<=3e5;i++){
			if(vis[i]) cnt[i]++;
		}
		memset(vis,0,sizeof vis);
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	return 0;
}
