#include<bits/stdc++.h>
using namespace std;
int n,m,a[2*100005],ans=0;
inline void read(int &x){
	x=0;int f=1;char c=getchar();
	for(;'9'<c||c<'0';c=getchar())if(c=='-')f=-1;
	for(;'0'<=c&&c<='9';c=getchar())x=(x<<3)+(x<<1)+(c^48);
	x=f*x;
}
bool vis[2*100005];
void dfs(int k,int x,int zhi){
	if(k==m){
		ans=max(ans,zhi);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			dfs(k+1,i,zhi&a[i]);
			vis[i]=false;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	read(n);read(m);
	int kk=0;
	for(int i=1;i<=n;i++){
		read(a[i]);
		kk=max(kk,a[i]);
	}
	for(int i=1;i<=n-m;i++){
		dfs(0,1,a[i]);
	}
	cout<<ans;
	return 0;
}
