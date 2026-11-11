#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,d,c,t,ans,a[2000005],nxt[2000005],pre[2000005],f[2000005],g[2000005];
int read(){
	int r=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))r=(r<<1)+(r<<3)+(ch&15),ch=getchar();
	return r*f;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	if(c<=10){
		while(t--){
			n=read(),d=read();ans=0;
			for(int i=1;i<=n;i++)a[i]=read();
			for(int i=1;i<=n;i++){
				nxt[i]=i;
				while(nxt[i]<n&&a[nxt[i]+1]-a[i]<=d)nxt[i]++;
			}
			for(int i=1;i<=n;i++){
				int sum=0;f[i]=0,g[i]=1;
				for(int j=i-1,k=i,l=i;j;j--){
					f[j]=1e9;
					f[j]=f[min(i,nxt[j])]+1;if(f[j]>=1e9)break;
					while(l>j&&f[l]==f[j]-1)sum+=g[l],l--;
					while(f[k]!=f[j]-1||k>nxt[j])sum-=g[k],k--;
					g[j]=min(sum,3ll);if(g[j]==2)ans++;
				}
			}
			printf("%lld\n",ans);
		}
		return 0;
	}
	if(c==13||c==14){
		while(t--){
			n=read(),d=read();ans=0;
			for(int i=1;i<=n;i++)a[i]=read();
			for(int i=1;i<=n;i++){
				nxt[i]=i;
				while(nxt[i]<n&&a[nxt[i]+1]-a[i]<=d)nxt[i]++;
			}
			for(int i=1;i<=n;i++){
				pre[i]=i;
				while(pre[i]>1&&a[i]-a[pre[i]-1]<=d)pre[i]--;
			}
			for(int i=1,l=1,r=1;i<=n;i++){
				while(l<=n&&a[l]-a[i]<=d)l++;
				while(l<=n&&nxt[i]-pre[l]>=2)l++;
				r=max(r,l);
				while(r<=n&&nxt[i]-pre[r]==1)r++;
				ans+=r-l;
			}
			printf("%lld\n",ans);
		}
		return 0;
	}
	return 0;
}