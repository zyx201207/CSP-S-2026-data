#include<bits/stdc++.h>
using namespace std;
long long n,m,inf=-1;
long long a[200005];
long long f[2005][2005];
void dp(int id,int w){
	if(w>m||id>n){
		return;
	}
	dp(id+1,w);
	f[id][w+1]=f[id][w]&a[id];
	dp(id+1,w+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			f[i][j]=-1;
		}
	}
	dp(1,0);
	printf("%lld",f[n][m]);
}
