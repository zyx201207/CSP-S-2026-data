#include<bits/stdc++.h>
#define LL long long
using namespace std;
const LL N=5e5+5;
LL a[N],sum[N];
bool vis[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	LL n,m;
	cin>>n>>m;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
	}
	for(LL i=1;i<=n;i++){
		memset(vis,0,sizeof vis);
		bool f=1;
		for(LL j=i;j<=n;j++){
			if(!vis[a[j]]){
				vis[a[j]]=1;
			}else{
				f=0;
				break;
			}
		}
		if(f){
			for(LL j=i;j<=n;j++){
				sum[a[j]]++;
			}
			continue;
		}
		if(a[i]!=a[n]){
			sum[a[i]]++;
			sum[a[n]]++;
		}else{
			sum[a[i]]++;
		}
	}
	for(LL i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}
