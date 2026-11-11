#include<cstdio>
#include<iostream>
using namespace std;
#define MAXN 2000005

int c,t;
int n;
long long d;
long long a[MAXN];


namespace subtask1{

int ans;
int dis[5005][5005];
long long cnt[5005][5005];

void init(){
	ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) dis[i][j]=0,cnt[i][j]=1;
			else dis[i][j]=1e9,cnt[i][j]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=1&&a[i]-a[j]<=d;j--){
			dis[i][j]=1;
		}
		for(int j=i+1;j<=n&&a[j]-a[i]<=d;j++){
			dis[i][j]=1;
		}
	}
}
	
void Floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(i==k) continue;
			for(int j=1;j<=n;j++){
				if(j==k) continue;
				if(dis[i][j]>dis[i][k]+dis[k][j]) dis[i][j]=dis[i][k]+dis[k][j],cnt[i][j]=cnt[i][k]*cnt[k][j];
				else if(dis[i][j]==dis[i][k]+dis[k][j]) cnt[i][j]+=cnt[i][k]*cnt[k][j];
			}
		}
	}
}
	
void solve(){
	init();
	Floyd();
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(cnt[i][j]==2) ans++;
		}
	}
	cout<<ans<<'\n';
}

}
//
//int bio_search(int x){
//	int l=1,r=n;
//	while(l<=r){
//		int mid=(l+r)>>1;
//		if(a[mid]<=x) l=mid+1;
//		else r=mid-1;
//	}
//	return l;
//}
//
//struct BIT{
//	long long tr[MAXN];
//	int lowbit(int x) {return x&(-x);}
//	void add(int x,long long v) {for(int i=x;i<=n;i+=lowbit(i)) tr[i]+=v;}
//	long long ask(int x) {long long ret=0; for(int i=x;i;i-=lowbit(i)) ret+=tr[i]; return ret;}
//}tr1,tr2;
//
//long long dp1[MAXN],dp2[MAXN];
//
//void init(){
//	for(int i=1;i<=n;i++) tr1.tr[i]=tr2.tr[i]=dp1[i]=dp2[i]=0;
//}
//
//void solve(){
//	init();
//	for(int i=n;i>=1;i--){
//		int l1=bio_search(a[i]+d),l2=l1-1;
//		
//	}
//}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		subtask1::solve();
	}
	return 0;
}