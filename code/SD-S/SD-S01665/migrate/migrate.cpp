#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define int long long
using namespace std;
bool Test_MLE_Start;
constexpr int N=305;
int _=1,CID,n,d,ans=0,a[N],dis[N][N],cnt[N][N];
bool Test_MLE_End;
inline int reads(){
	char c=getchar();
	int x=0,f=1;
	while(!isdigit(c)){
		if(c=='-') f=-1;
		c=getchar();
	}while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}inline void clr(){
//	Don't Forget!
	ans=0;
	memset(cnt,0,sizeof(cnt));
	memset(dis,0x3f,sizeof(dis));
}inline void files(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
}signed main(){
//	printf("%lf\n",(&Test_MLE_End-&Test_MLE_Start+1)/1024.0/1024.0);
	files();
	CID=reads(),_=reads();
	while(_--){
		clr();n=reads(),d=reads();
		for(int i=1;i<=n;i++) a[i]=reads();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(abs(a[i]-a[j])<=d&&i!=j)  dis[i][j]=1,cnt[i][j]=1;
			}
		}for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i==j||i==k||j==k) continue;
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(dis[i][k]+dis[k][j]==dis[i][j]) cnt[i][j]++;
				}
			}
		}for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(cnt[i][j]==2) ans++;
			}
		}printf("%lld\n",ans);
	}return 0;
}
/*
18:10 I can't pass simple 3! Why?
真服气了哥们 
*/
