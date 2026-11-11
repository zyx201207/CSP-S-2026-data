#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
ll n,m,cnt[35],ans,num;
bool vis[N][35];
void get_zero(int x){
	for(int i=0;i<=30;i++){
		if(vis[x][i]){
			vis[x][i]=0;
			cnt[i]--;	
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%lld",&x);
		num++;
		for(int j=0;j<=30;j++){
			if(1&(x>>j)){
				cnt[j]++;
				vis[i][j]=1;
			}
		}
	}
	for(int i=30;i>=0;i--){
		if(cnt[i]>=m){
			for(int j=1;j<=n;j++){
				if(vis[j][i]==0){
					get_zero(j);
				}
			}
			ans+=(1<<i);
		}
	}
	printf("%lld",ans);
	return 0;
}
