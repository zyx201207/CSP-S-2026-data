#include<bits/stdc++.h>
using namespace std;
#define maxn 2000005
#define maxm 1005
#define int long long
int c,t,n,d,k,a[maxn];
int dis[maxm][maxm],cnt[maxm][maxm];
int ans;
int read(){
	int f=1,ret=0;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-'){f=-1;}ch=getchar();}
	while(isdigit(ch)){ret=ret*10+ch-'0';ch=getchar();}
	return ret*f;
}
int find(){
	int L=2,R=100;
	while(L<=R){
		int mid=(L+R)/2;
		if((mid-1)*k>=n && mid*k<n) return mid;
		if((mid-1)*k<n) L=mid+1;
		else R=mid-1;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--){
		ans=0;
		memset(dis,-1,sizeof dis);
		memset(cnt,0,sizeof cnt);
		n=read(),d=read();
		for(int i=1;i<=n;i++) a[i]=read();
		if(c==11 || c==12 || c==0){
			k=a[2]-a[1];
			if(d>=k){
				printf("%lld\n",max(n-find()*2+1,0LL));
			}
			else{
				printf("0\n");
			}
			continue;
		}
		for(int i=1;i<=n;i++){
			int j=i+1;
			while(a[j]-a[i]<=d && j<=n) dis[i][j]=dis[j][i]=1,cnt[i][j]=cnt[j][i]=1,j++;
			j=i-1;
			while(a[i]-a[j]<=d && j>=1) dis[i][j]=dis[j][i]=1,cnt[i][j]=cnt[j][i]=1,j--;
		}
		for(int len=1;len<n;len++){
			for(int i=1;i<=n-len;i++){
				int j=i+len;
				for(int k=i+1;k<j;k++){
//					if(i==1 && j==4 && k==3) printf("%d %d ",dis[1][3],dis[3][4]);
					if(dis[i][k]==-1 || dis[k][j]==-1){
						continue;
					}
					if(dis[i][j]!=-1) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
					else dis[i][j]=dis[i][k]+dis[k][j];
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=i+1;k<j;k++){
					if(dis[i][k]+dis[k][j]==dis[i][j]){
						cnt[i][j]+=cnt[i][k]*cnt[k][j];
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(cnt[i][j]==2){
					ans++;
				}
			}
		}
//		printf("%d %d ",dis[1][3],dis[3][4]);
//		printf("%d %d %d ",cnt[1][3],cnt[3][4],cnt[1][4]);
		printf("%lld\n",ans);
	}
	return 0;
}
