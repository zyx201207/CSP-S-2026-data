#include<bits/stdc++.h>
using namespace std;
long long csd,t,n,d,a[2000010],b[20],sum=0,ans=0,s;
void f(long long k,long long m,long long s1){
	if(k==m){
		s=min(s,s1);
		return ;
	}
	for(int i=k+1;i<=m;i++){
		if(a[i]-a[k]<=d){
			f(i,m,s1+1);
		}else return ;
	}
}
void dfs(long long k,long long m,long long s1){
	if(s1>s)return ;
	if(k==m){
		sum++;
		return ;
	}
	for(int i=k+1;i<=m;i++){
		if(a[i]-a[k]<=d){
			b[s1]=i;
			dfs(i,m,s1+1);
		}else return ;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld %lld",&csd,&t);
	while(t--){
		scanf("%lld %lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",a+i);
		}
		if(d==1){
			cout<<"0\n";
			continue;
		}
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				sum=0,s=LLONG_MAX;
				f(i,j,1);
				b[0]=i;
				dfs(i,j,1);
				if(sum==2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}