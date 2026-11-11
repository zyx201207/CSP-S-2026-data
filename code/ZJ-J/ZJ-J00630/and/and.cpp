#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
int n,k,a[maxn],ans,b[maxn][25],c[25],maxx,p_2[45],Ta,Tb,Tc;
bool vis[maxn];
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
void init(){
	p_2[0]=1;
	for(int i=1;i<=30;i++)p_2[i]=p_2[i-1]*2;
}
void dfs(int now,int x){
	if(x==k){
		ans=max(ans,now);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		dfs(now&a[i],x+1);
		vis[i]=0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	init();
	n=read(),k=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]<4)Tc++;
		for(int j=1;j<=30;j++){
			if(a[i]+1==p_2[j]){Ta++;break;}
		}
	}
	if(n<=20){
		for(int i=1;i<=n;i++){
			vis[i]=1;
			dfs(a[i],1);
			vis[i]=0;
		}
		printf("%d\n",ans);
		return 0;
	}
	if(k==1){
		for(int i=1;i<=n;i++)ans=max(ans,a[i]);
		printf("%d\n",ans);
		return 0;
	}
	if(k==n){
		ans=a[1];
		for(int i=2;i<=n;i++)ans=ans&a[i];
		printf("%d\n",ans);
		return 0;
	}
	if(k==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				ans=max(ans,a[i]&a[j]);
			}
		}
		printf("%d\n",ans);
		return 0;
	}
	if(k==n-1){
		for(int i=1;i<=n;i++){
			int x=a[i];
			b[i][0]=0;
			while(x){
				b[i][0]++;
				if(x&1){
					c[b[i][0]]++;
					b[i][b[i][0]]=1;
				}else b[i][b[i][0]]=0;
				x>>=1;
			}
			maxx=max(maxx,b[i][0]);
		}
		for(int i=maxx;i>=0;i--){
			if(c[i]!=k)continue;
			if(c[i]==k){
				int now;
				for(int j=1;j<=n;j++){
					if(b[j][i]==0){now=j;break;}
				}
				if(now==1){
					ans=a[2];
					for(int i=3;i<=n;i++)ans=ans&a[i];
					printf("%d\n",ans);
					return 0;
				}else{
					ans=a[1];
					for(int i=2;i<=n;i++){
						if(i==now)continue;
						ans=ans&a[i];
					}
					printf("%d\n",ans);
					return 0;
				}
			}
		}
	}
	if(Ta==n){
		sort(a+1,a+1+n);
		reverse(a+1,a+1+n);
		printf("%d\n",a[k]);
		return 0;
	}
	if(Tc==n){
		sort(a+1,a+1+n);
		reverse(a+1,a+1+n);
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
			if(i==k){
				printf("%d\n",ans);
				return 0;
			}
		}
	}
	sort(a+1,a+1+n);
	reverse(a+1,a+1+n);
	ans=a[1];
	for(int i=2;i<=k;i++)ans=ans&a[i];
	printf("%d\n",ans);
	return 0;
}
