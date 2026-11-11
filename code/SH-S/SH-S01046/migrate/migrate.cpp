#include<bits/stdc++.h>
#define int long long 
using namespace std;
int c,t;
int n,d;
int x[2000010];
int pre[2000010];
int nxt[2000010];
int sumpre[2000010];
int sumnxt[2000010];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			pre[i]=0;
			nxt[i]=0;
			sumpre[i]=0;
			sumnxt[i]=0;
			scanf("%lld",&x[i]);
		}
		int l=1;
		for(int i=1;i<=n;i++){
			if(x[i]-x[l]<=d){
				nxt[l]=i-l;
			}
			else{
				while(x[i]-x[l]>d){
					l++;
					//nxt[l]=nxt[l-1]-1;
				}
				nxt[l]=i-l;
			}
		}
		while(l<n){
			l++;
			nxt[l]=nxt[l-1]-1;
		}
		l=n;
		for(int i=n;i>=1;i--){
			if(x[l]-x[i]<=d){
				pre[l]=l-i;
			}
			else{
				while(x[l]-x[i]>d){
					l--;
					//pre[l]=pre[l+1]-1;
				}
				pre[l]=l-i;
			}
		}
		while(1<l){
			l--;
			pre[l]=pre[l+1]-1;
		}
		
		
		l=1;
		for(int i=2;i<=n;i++){
			if(nxt[i-1]==1&&pre[i]==1){
				//sum++;
				sumpre[i]=i-l;
			}
			else{
				l=i;
				sumpre[i]=0;
			}
		}
		l=n;
		for(int i=n-1;i>=1;i--){
			if(pre[i+1]==1&&nxt[i]==1){
				sumnxt[i]=l-i;
			}
			else{
				l=i;
				sumnxt[i]=0;
			}
		}
		//for(int i=1;i<=n;i++){
		//	printf("%lld ",sumpre[i]);
		//}
		//puts("");
		//for(int i=1;i<=n;i++){
		//	printf("%lld ",sumnxt[i]);
		//}
		//puts("");
		//vector<pair<int,int> >ans;
		int llans=0;
		for(int i=1;i+3<=n;i++){
			if(nxt[i]==2&&pre[i+3]==2){
				//ans.push_back({i,i+3});
				llans+=(sumpre[i]+1)*(sumnxt[i+3]+1);
				//llans++;
				//printf("%lld %lld\n",i,i+3);
			}
		}
		printf("%lld\n",llans);
	}
}
