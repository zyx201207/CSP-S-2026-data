#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,k[210000],a[210000][40];
bool flag[210000];
long long ksm(long long di,long long zhi){
	long long mi=1;
	while(zhi>0){
		if(zhi%2==1){
			mi*=di;
		}
		di=di*di;
		zhi/=2;
	}
	return mi;
}
void findmx(long long x){
	for(long long j=x;j>=1;j--){
		long long cnt=0;
		for(long long i=1;i<=n;i++){
			if(flag[i]==0){
				if(a[i][j]==1){
					cnt++;
				}
			}
		}
		if(cnt>=m){
			ans+=ksm(2,j-1);
			for(long long i=1;i<=n;i++){
				if(a[i][j]!=1){
					flag[i]=1;
				}
			}
		}
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long Max=0;
	for(long long i=1;i<=n;i++){
		long long x;
		cin>>x;
		while(x>0){
			a[i][++k[i]]=x%2;
			x/=2;
		}
		Max=max(Max,k[i]);
	}
	findmx(Max);
	cout<<ans<<"\n";
	return 0;
}
