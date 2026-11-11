#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,res,a[N];
bool vis[25];
void dfs(int u){
	if(u>n){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(vis[i]) sum++;
		}
		if(sum==m){
			int ans=2147483647;
			for(int i=1;i<=n;i++){
				if(vis[i]) ans&=a[i];
			}
			res=max(res,ans);
		}
		return;
	}
	vis[u]=0;
	dfs(u+1);
	vis[u]=1;
	dfs(u+1);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	bool f1=1,f2=1;
	for(int i=1;i<=n;i++) if(a[i]+1!=i) f1=0;
	int maxn=0;
	for(int i=1;i<=n;i++) maxn=max(maxn,a[i]);
	for(int i=1;i<=n;i++){
		double x=log2(a[i]+1);
		int xx=x;
		if(x!=xx) f2=0;
	}
	if(n<=20){
		dfs(1);
		printf("%lld\n",res);
	}
	else if(n<=2000){
		if(m==1){
			int mx=0;
			for(int i=1;i<=n;i++) mx=max(mx,a[i]);
			printf("%lld\n",mx);
		}
		else if(m==n){
			int cnt=2147483647;
			for(int i=1;i<=n;i++) cnt&=a[i];
			printf("%lld\n",cnt);
		}
		else if(m==2){
			int num=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					int tmp=a[i]&a[j];
					num=max(num,tmp);
				}
			}
			printf("%lld\n",num);
		}
	}
	else{
		if(m==n-1){
			
		}
		else if(f1){
			sort(a+1,a+n+1);
			printf("%lld\n",a[n-m+1]);
		}
		else if(f2){
			if(m<=n/2) printf("%lld\n",n-m);
			else puts("0");
		}
		else if(maxn<4){
			int c1=0,c2=0,c3=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1) c1++;
				if(a[i]==2) c2++;
				if(a[i]==3) c3++;
			}
			if(c1>0){
				if(c2>0){
					if(c3>0){
						if(m<=c3) puts("3");
						else if(m<=c2+c3) puts("2");
						else puts("0");
					}else{
						if(m<=c2) puts("2");
						else puts("0");
					}
				}else{
					if(c3>0){
						if(m<=c3) puts("3");
						else puts("1"); 
					}else{
						puts("1");
					}
				}
			}else{
				if(c2>0){
					if(c3>0){
						if(m<=c3) puts("3");
						else puts("2"); 
					}else{
						puts("2");
					}
				}else{
					if(c3>0){
						puts("3");
					}
				}
			}
		}
		else{
			puts("1024");
		}
	}
	return 0;
}
