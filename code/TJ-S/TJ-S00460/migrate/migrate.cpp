#include<cstdio>
#include<algorithm>
#include<vector>
#include<cassert>
template <typename T >bool relax(T &a,const T &b){return b>a?a=b,true:false;}
template <typename T >bool tense(T &a,const T &b){return b<a?a=b,true:false;}
const int N=2000005;
const int INF=0x3f3f3f3f;
const long long INFll=0x3f3f3f3f3f3f3f3fll;
int C,T,n;
long long d;
long long a[N];
namespace Force{
	const int NN=305;
	int dis[NN][NN];
	long long cnt[NN][NN];;
	void solve(){
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
			dis[i][j]=INF,cnt[i][j]=1;
		}
		for(int i=1;i<=n;i++) dis[i][i]=0,cnt[i][i]=0;
		for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(a[j]-a[i]<=d){
			tense(dis[i][j],1),tense(dis[j][i],1);
		}
		for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)if(i!=j){
			if(tense(dis[i][j],dis[i][k]+dis[k][j])){
				cnt[i][j]=0;
			}
			if(dis[i][j]==dis[i][k]+dis[k][j]){
				cnt[i][j]+=1ll*cnt[i][k]*cnt[k][j];
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(cnt[i][j]==2) {
			//printf("%d %d\n",i,j);
			ans++;
		}
		printf("%lld\n",ans);
	}
}
namespace Better{
	int maxnext[N],maxpre[N],secnext[N];
	int tol[N],tor[N],toi[N];
	struct rec{
		long long l,r;	
		int cnt;
	}b[N];
	int m=0;
	void solve(){
		for(int i=1,j=1;i<=n;i++){
			while(j<=i&&a[i]-a[j]>d) j++;
			maxpre[i]=j;
		}
		for(int i=n,j=n;i>=1;i--){
			while(j>=i&&a[j]-a[i]>d) j--;
			maxnext[i]=j>i?j:INF+i;
			secnext[i]=j>i+1?j-1:-INF-i;
			//printf("%d %d %d\n",i,maxnext[i],secnext[i]);
		}
		m=0;
		for(int i=1,j=1;i<=n;i=++j){
			while(j<n&&maxnext[j]==j+1&&maxpre[j+1]==j) j++ ;
			b[++m]=(rec){i,j,j-i+1};
			for(int k=i;k<=j;k++) tol[k]=i,tor[k]=j,toi[k]=m;
		}
		//for(int i=1;i<=m;i++) printf("%lld %lld %d\n",b[i].l,b[i].r,b[i].cnt);

		long long ans=0;
		for(int i=1;i<=m;i++){
			//if(i==2) printf("%d^%d %d\n",maxnext[b[i].r],tor[maxnext[b[i].r]],maxnext[tor[maxnext[b[i].r]]]);
			bool f1=true,f2=true,f3=true;
			if(secnext[b[i].r]<=-INF) f2=false;
			if(maxnext[b[i].r]>=INF) continue;
			if(secnext[tor[maxnext[b[i].r]]]<=-INF) f3=false;
			if(maxnext[tor[maxnext[b[i].r]]]>=INF) f1=false;
			//printf("%d@@@ %d\n",secnext[b[i].r],maxnext[tor[secnext[b[i].r]]]);
			if(f2&&maxnext[tor[secnext[b[i].r]]]>=INF) f2=false;
			//printf("%d %d %d %d\n",f1,f2,f3,secnext[tor[maxnext[b[i].r]]]);
			int x1=f1?tor[maxnext[tor[maxnext[b[i].r]]]]:0;
			int x2=f2?tor[maxnext[tor[secnext[b[i].r]]]]:0;
			int x3=f3?tor[secnext[tor[maxnext[b[i].r]]]]:0;
			//printf("%d\n",i);
			//if(i==3) printf("%d %d %d\n",x1,x2,x3); 
			if(f1&&f2&&x1==x2&&(x1!=x3||!f3)) ans+=1ll*b[i].cnt*b[toi[x2]].cnt;
			if(f1&&f3&&x1==x3&&(x1!=x2||!f2)) ans+=1ll*b[i].cnt*b[toi[x3]].cnt;
			if(f2&&f3&&x2==x3&&(x1!=x2||!f1)) ans+=1ll*b[i].cnt*b[toi[x3]].cnt;
		}
		printf("%lld\n",ans); 
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&C,&T);
	while(T--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		if(n<=300) Force::solve();
		else Better::solve();
	}
	
	return 0;	
}
