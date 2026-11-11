#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+10;
LL n,m,k,ans=-1,now=-1,g=1;
LL a[N]; 
bool vis[N];
void dfs(int u){
	if(u==n+1){
		if(k==0) ans=max(ans,now);
		return ;
	}
	if(k==0){
		ans=max(ans,now);
		return ;
	}
	if(n-g<k){
		return ;
	}
//	cerr<<u<<" "<<k<<" "<<now<<endl;
	for(int i=g;i<=n;i++){
		if(!vis[i]&&k>0){
			LL t=now,w=g;
			now&=a[i];g=i;
			vis[i]=true;
			k--;
			dfs(u+1);
			now=t;g=w;
			k++;
			vis[i]=false;
		}
		dfs(u+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	k=m;
	for(LL i=1;i<=n;i++){
		scanf("%lld",a+i); 
	}
	if(m==1){
		ans=-1;
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
	}else if(m==n){
		ans=-1;
		for(int i=1;i<=n;i++){
			ans&=a[i];
		}
	}else{
		dfs(1);
	}
	printf("%lld",ans);
	return 0;
}

