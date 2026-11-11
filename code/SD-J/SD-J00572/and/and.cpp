#include<bits/stdc++.h>
#define int long long
using namespace std;
bool flag[200005];
int n,m,a[200005],sum,f[50][200005];
void work(int id){
	int x=a[id];
	int tot=0,p[50];
	for(int i=1;i<=35;i++)p[i]=0;
	while(x){
		p[tot]=x%2;
		x/=2;
		tot++;
	}
	for(int i=0;i<tot;i++){
		f[i][id]=p[i];
	}
}
bool qu(int id){
	int ans=0;
	for(int i=1;i<=n;i++){
		if(f[id][i]==1 && flag[i])
		  ans++;
	}
	if(ans>=m){
		for(int i=1;i<=n;i++)
		if(f[id][i]==0)
		  flag[i]=0;
	}
	return ans>=m;
}
int mi(int k){
	int ans=1;
	for(int i=1;i<=k;i++)
	  ans*=2;
	return ans;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	memset(flag,1,sizeof flag);
	int sum=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		work(i);
	}
	for(int i=35;i>=0;i--){
		if(qu(i)){
			sum+=mi(i);
		}
	}
	printf("%lld",sum);
	return 0;
}
