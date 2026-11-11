#include<bits/stdc++.h>
using namespace std;
long long m,n,a[200010],ans;
long long f[2010][2010];

bool pd[200010];
void bl(long long dqg,long long dq){
	if(dqg==m){
		ans=max(dq,ans);
	}else{
		for(int i=1;i<=n;i++){
			if(pd[i]==0){
				pd[i]=1;
				bl(dqg+1,dq&a[i]);
				pd[i]=0;
			}
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(n<=20){
		for(int i=1;i<=n;i++){
			pd[i]=1;
			bl(1,a[i]);
			pd[i]=0;
		}
		printf("%lld",ans);
	}else{
		for(int i=1;i<=n;i++){
			f[i][1]=max(f[i-1][1],a[i]);
			for(int j=2;j<=m;j++){
				f[i][j]=max(f[i-1][j-1]&a[i],f[i-1][j]);
			}
		}
		printf("%lld",f[n][m]);
	}
	return 0;
	
}