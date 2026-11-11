#include<bits/stdc++.h>
using namespace std;
long long n,m,w,x;
long long a[200001],b[200001],c[200001];
int zhuan(long long x,long long b[]){
	long long i=x;
	while(i!=0){
		b[x]=i%2*10+b[x];
		i/=2;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long maxn=0;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		zhuan(a[i],b);
	}
	long long ans=0;
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=m;j++){
			c[j]=b[i+j];
			long long k=c[1]&c[2];
			ans=max(ans,k);
			for(long long v=3;v<=m;v++){
				k=k&c[v];
				ans=max(ans,k);
			}
		}
	}
	long long d[200001];
	for(int i=1;ans!=0;i++){
		d[i]=ans%10;
		ans/=10;
		w++;
	}
	for(int i=1;i<=w;i++){
		ans+=d[i]*pow(2,i-1);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
