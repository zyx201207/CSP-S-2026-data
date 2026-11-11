#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5010,M=2e6+10;
const int inf=0x3f3f3f3f;
int c,t,n,dis[N],R[M],Lst[M][2];
ll x[N],d,cnt[N];
bool flag[N];
vector <int> e[N];
queue <int> Q;
void solve1(){
	ll ans=0;
	for(int i=1;i<=n;i++)e[i].clear();
	for(int i=1;i<=n;i++){
		//printf("%d ",i);
//		for(int j=i-1;j>=1;j--){
//		//	printf("	%d %d %d\n",i,j,x[i]-x[j]);
//			if(x[i]-x[j]<=d)e[i].push_back(j);//printf("	%d %d\n",i,j);
//			else break;
//		}
		for(int j=i+1;j<=n;j++){
			if(x[j]-x[i]<=d)e[i].push_back(j);//printf("	%d %d\n",i,j);
			else break;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)dis[j]=inf,cnt[j]=0;
		Q.push(i);flag[i]=1;dis[i]=0;cnt[i]=1;
		while(!Q.empty()){
			int x=Q.front();Q.pop();
			flag[x]=0;
			for(auto y:e[x]){
				if(dis[y]<dis[x]+1)continue;
				if(dis[y]==dis[x]+1)cnt[y]+=cnt[x];
				if(dis[y]>dis[x]+1){
					dis[y]=dis[x]+1;
					cnt[y]=cnt[x];
				}
				if(flag[y])continue;
				Q.push(y);
				flag[y]=1;
			}
		}
//		for(int j=1;j<i;j++)printf("0 ");
//		for(int j=i;j<=n;j++)printf("%lld ",dis[j]);
//		printf("\n");
//		for(int j=1;j<i;j++)printf("0 ");
//		for(int j=i;j<=n;j++)printf("%lld ",cnt[j]);
//		printf("\n");
		for(int j=1;j<=n;j++)
			if(cnt[j]==2)ans++;//printf("ans=%d %d\n",i,j);
	//	printf("%d %d\n",i,tmp);
	}
	printf("%lld\n",ans);
}
ll getans(int l,int r){
	if(l>r)return 0;
	ll tmp=0;
	if(l==r&&Lst[r][0])return Lst[r][0];
	if(l<r&&Lst[r][1])return Lst[r][1];
	if(l!=r)tmp+=R[r-1]-R[r-2];
//	if(R[r]==r){
//	//	printf("%d %d %d\n",l,r,tmp);
//		return tmp;
//	}
	tmp+=getans(R[r-1]+1,R[r]);
//	printf("%d %d %d\n",l,r,tmp);
	if(l==r)Lst[r][0]=tmp;
	if(l<r)Lst[r][1]=tmp;
	return tmp;
}
void solve2(){
	ll ans=0;
	int l=1,r=1;
	for(;l<=n;l++){
		Lst[l][0]=Lst[l][1]=0;
		while(x[r]-x[l]<=d&&r<=n)r++;
		R[l]=r-1;
	//	printf("%d ",R[l]);
	}
	ll lstans=0;
//	Lst[n]=0;
	for(int i=n-1;i>=1;i--){
		ans+=getans(i,R[i]);
	//	printf("%d %d\n",i,getans(i+1,R[i]));
	//	printf("%d %d\n",i,lstans);
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		ll ans=0;
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
		if(n<=5000)solve1();
		else solve2();
	}
	return 0;
}

