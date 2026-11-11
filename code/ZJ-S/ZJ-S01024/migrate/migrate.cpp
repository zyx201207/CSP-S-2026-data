#include<bits/stdc++.h>
#define ll long long
#define pa pair<int,int>
#define fi first
#define se second
#define N 2000050
using namespace std;
ll x[N];
int tiaohou[N],tiaoqian[N];
ll qian[N],hou[N];
ll dpqian[N],dphou[N];
void solve(){
	int n;ll d;
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;i++){
		scanf("%lld",&x[i]);
	}
	tiaohou[n]=n;
	for(int i=n-1;i>=1;i--){
		tiaohou[i]=tiaohou[i+1];
		while(x[tiaohou[i]]-x[i]>d)tiaohou[i]--;
	}
	tiaoqian[1]=1;
	for(int i=2;i<=n;i++){
		tiaoqian[i]=tiaoqian[i-1];
		while(x[i]-x[tiaoqian[i]]>d)tiaoqian[i]++;
	}
//	for(int i=1;i<=n;i++){
//		printf("%d %d %d\n",i,tiaoqian[i],tiaohou[i]);
//	}
	for(int i=1;i<=n;i++){
		qian[i]=hou[i]=0;
		dpqian[i]=dphou[i]=0;
	}
	for(int i=1;i<=n;i++){
		if(tiaohou[i]!=i){
			int tiao=tiaohou[i];
			if(tiaoqian[tiao]==i){
				qian[tiao]+=qian[i];
			}
			if(tiaoqian[tiao]<=i){
				qian[tiao]++;
			}
			if(i<tiao-1){
				if(tiaoqian[tiao-1]==i){
					dpqian[tiao-1]+=qian[i];
				}
				if(tiaoqian[tiao-1]<=i){
					dpqian[tiao-1]++;
				}
			}
		}
	}
	for(int i=n;i>=1;i--){
		if(tiaoqian[i]!=i){
			int tiao=tiaoqian[i];
			if(tiaohou[tiao]==i){
				hou[tiao]+=hou[i];
			}
			if(tiaohou[tiao]>=i){
				hou[tiao]++;
			}
			if(tiao+1<i){
				if(tiaohou[tiao+1]==i){
					dphou[tiao+1]+=hou[i];
				}
				if(tiaohou[tiao+1]>=i){
					dphou[tiao+1]++;
				}
			}
		}
	}
	ll ans=0;
	for(int i=1;i<n;i++){
		ans+=dpqian[i]*dphou[i+1];
	}
	printf("%lld\n",ans);
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;scanf("%d%d",&c,&t);
	while(t--){
		solve();
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/
