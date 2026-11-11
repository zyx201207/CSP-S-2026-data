#include<bits/stdc++.h>
using namespace std;
const int maxx=2e6+5;
int c,t,n;
long long d;
long long a[maxx];
int z[5005][5005];
int ans=0;
bool pd(int i,int j){
	if(abs(a[i]-a[j])<=d){
		return 1;
	}
	return 0;
}
void solve(){
	for(int len=1;len<=n;len++){
		for(int l=1;l+len-1<=n;l++){
			int r=l+len-1;
			if(pd(l,r)){
				z[l][r]=1;
				continue;
			}
			int max_=INT_MAX,id=0;
			for(int k=l;k<=r;k++){
				int p=z[l][k]+z[k][r];
				z[l][r]=min(z[l][r],p);
				if(p<max_){
					max_=z[l][r];
					id=1;
				}
				else if(p==max_){
					id++;
				}
			}
			if(id==2){
				ans++;
			}
		}
	}
	
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	int tt=t;
	if(c<=6){
		while(tt--){
			scanf("%d%lld",&n,&d);
			ans=0;
			memset(z,0x3f,sizeof(z));
			for(int i=1;i<=n;i++){
				scanf("%lld",&a[i]);
				z[i][i]=0;
			}
			solve();
			printf("%d\n",ans);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
