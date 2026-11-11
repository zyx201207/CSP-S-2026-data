#include<bits/stdc++.h>
#define ll long long

using namespace std;
const int N=2e6+5;
int c,tt,n;
ll d,a[N];
int ed[N];
int nxt[N];
ll H(int l,int r){return 1ll*l*(n+1)+r;}
unordered_map<ll,bool>mp,mp1;
void solve(){
	scanf("%d%lld",&n,&d);
	mp.clear(),mp1.clear();
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	ed[n]=n;
	for(int i=n-1;i>=1;i--)ed[i]=(a[i+1]-a[i]>d?i:ed[i+1]);
	for(int i=1,j=1;i<=n;i++){
		j=max(i,j);
		while(j<n&&a[j+1]-a[i]<=d)j++;
		nxt[i]=j;
		if(j==i||j==i+1)continue;
		for(int k=j+1;k<=ed[i];k++){
			if(a[k]-a[j-1]>d)break;
			if(a[k]-a[j-2]>d)mp[H(i,k)]=1;
			else mp1[H(i,k)]=1;
		}
	}
//	for(int i=1;i<=n;i++)printf("%d ",nxt[i]);
	int ans=0;
	for(int i=1;i<=n;i++){
		if(nxt[i]==i)continue;
		int lst2=i,lst=nxt[i];
		int cnt=0;
		for(int j=nxt[i]+1;j<=ed[i];j++){
			if(j==nxt[lst]){
				if(mp1[H(lst2,j)])break;
				if(mp[H(lst2,j)]){
					cnt++;
					if(cnt>1)break;
				}
				lst2=lst,lst=j;
			}
			if(cnt+mp[H(lst2,j)]==1)ans++;
		}
//		printf("%d ",ans);
	}
	printf("%d\n",ans);
}
int pre[N];
int pp[N],nn[N];
struct Pair1{int x,y;};
void solve2(){
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	if(n<=3){puts("0");return;}
	pre[1]=1;
	for(int i=2;i<=n;i++)pre[i]=(a[i]-a[i-1]>d?i:pre[i-1]);
//	for(int i=1;i<=n;i++)printf("%d ",pre[i]);
//	puts("");
	nxt[n]=n;
	for(int i=n-1;i>=1;i--)nxt[i]=(a[i+1]-a[i]>d?i:nxt[i+1]);
//	for(int i=1;i<=n;i++)printf("%d ",nxt[i]);
//	puts("");
	for(int i=1,j=1;i<=n;i++){
		while(j<i&&a[i]-a[j+1]>d)j++;
		if(a[i]-a[j]>d)pp[i]=j;
		else pp[i]=0;
	}
//	for(int i=1;i<=n;i++)printf("%d ",pp[i]);
//	puts("");
	for(int i=n,j=n;i>=1;i--){
		while(j>i&&a[j-1]-a[i]>d)j--;
		if(a[j]-a[i]>d)nn[i]=j;
		else nn[i]=n+1;
	}
//	for(int i=1;i<=n;i++)printf("%d ",nn[i]);
//	puts("");
//	return;
	vector<Pair1>xx;
	for(int i=1;i<=n-3;i++){
		if(pp[i+3]==0||pp[i+3]==i+1||pp[i+3]==i+2)continue;
		if(nn[i]==n+1||nn[i]==i+1||nn[i]==i+2)continue;
		if(a[i+2]-a[pp[i+3]]<=d&&a[nn[i]]-a[i+1]<=d)xx.push_back({pp[i+3],nn[i]});
	}
//	vector<int>xx;
//	for(int i=1;i<=n-3;i++)if(a[i+2]-a[i]<=d&&a[i+3]-a[i+1]<=d&&a[i+3]-a[i]>d)xx.push_back(i);
	int ln=xx.size();
	ll ans=0;
	for(int i=0;i<ln;i++){
//		if(i!=0&&(xx[i-1].x==xx[i].x||xx[i-1].y==xx[i].y))continue;
//		if(i!=ln-1&&(xx[i+1].x==xx[i].x||xx[i+1].y==xx[i].y))continue;
		int lb=(i==0?pre[xx[i].x]:max(pre[xx[i].x],xx[i-1].x+1));
		int rb=(i==ln-1?nxt[xx[i].y]:min(nxt[xx[i].y],xx[i+1].y-1));
//		printf("%d %d %d\n",xx[i],lb,rb);
		ans+=1ll*(xx[i].x-lb+1)*(rb-xx[i].y+1);//printf("%d %d %lld\n",xx[i].x,xx[i].y,ans);
	}
	printf("%lld\n",ans);
}
signed main()
{
	freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&tt);
	if(c<=10){while(tt--)solve();}
	else{
	while(tt--)solve2();
	}
	return 0;
}