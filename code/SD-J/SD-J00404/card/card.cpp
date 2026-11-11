#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 500005
#define M 300005
int n,m;
int a[N];
int nxt[N];
int cnt[M];
int kk[M];
bool cx[M];
int la[M];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
//		for(int j=1;j<=m;j++){
//			cx[j]=1;
//		}
		int u=a[i];
		cx[u]=1;
		if(!kk[u]){
			kk[u]=i;
//			cx[u]=1;
			la[u]=i;
		}else{
			nxt[i]=kk[u];
			kk[u]=i;
			for(int j=i+1;j<nxt[i];j++){
				int v=a[j];
				if(la[v]<nxt[i]||la[v]==0){
					cx[v]=0;
				}
			} 
		}
		for(int j=1;j<=m;j++){
			cnt[j]+=cx[j];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
} 
