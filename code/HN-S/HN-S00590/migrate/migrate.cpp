#include<bits/stdc++.h>
using namespace std;
long long c,T,n,d,a[2000050],B[2000050],r,sum,maxn;
void dfs(long long x,long long l){
	if(x==r){
		B[l]++;
		maxn=max(maxn,l);
		return ;
	}
	for(long long i=x+1;i<=n;i++){
		if(abs(a[i]-a[x])<=d){
			dfs(i,l+1);
		}
		else{
			break;
		}
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		sum=0;
		memset(a,0,sizeof(a));
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>a[i];
		}
		for(long long i=1;i<=n;i++){
			for(long long j=i+2;j<=n;j++){
				memset(B,0,sizeof(B));
				r=j,maxn=0;
				dfs(i,0);
				for(long long l=1;l<=maxn;l++){
					if(B[l]==2){
						sum++;
						break;
					}
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
