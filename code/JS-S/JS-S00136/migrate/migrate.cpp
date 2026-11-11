#include <bits/stdc++.h>
using namespace std;
int c,t,res,k,op,ans;
long long n,d,a[2000010],b[2000010];
int g[2000010];
int vis[2000010];
bool check(int l,int r,int mid,int m){
	int vis=0;
	res=0;
	for(int i=l;i<=r;i++){
		if(vis>mid){res++;vis=0;}
		vis+=b[i];
		if(res>m)return false;
	}
	return true;
}
void dfs(int l,int r,int m){
	if(m==k+1){
		g[0]=1;g[k+1]=r;
		int f=1;
		for(int i=k+2;i>=1;i--){
			if((a[g[i]]-a[g[i-1]])>d){
				f=0;
				break;
			}
		}
		if(f==1)op++;
		return ;
	}
	for(int i=l+1;i<=r-1;i++){
		if(vis[i]==0){
			vis[i]=1;
			g[m]=i;
			dfs(l,r,m+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)b[i]=a[i]-a[i-1];
		for(int i=1;i<=n-3;i++){
			for(int j=i+3;j<=n;j++){
				int l=1,r=j-i,mid;
				k=INT_MAX;
				while(l<r){
					mid=(l+r)/2;
					if(check(i,j,mid,k)){k=res;r=mid;}
					l=mid+1;
				}
				memset(vis,0,sizeof(vis));
				dfs(i,j,1);
				if(op==2)ans++;
				op=0;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
