#include<bits/stdc++.h>
using namespace std;
struct mc{
	long long s;
	bool v[31]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
};
bool cmp(mc x,mc y){
	return x.s>y.s;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);long long ans=0;
	long long a[200005];
	for(int i = 1;i<=n;++i)
	cin>>a[i];
	if(m==2){
	for(int i = 1;i<=n;++i){
		for(int j = 1;j<=n;++j){
			if(i==j)continue;
			long long maxn=a[i]&a[j];
			ans=max(maxn,ans);
	}
	}
	}
	else if(m==1){
		for(int i = 1;i<=n;++i)
		ans=max(a[i],ans);}
	else if(m==n){
		ans=a[1];
		for(int i = 1;i<=n;++i){
			ans=ans&a[i];}
	}
	printf("%lld",ans);
	return 0;
}

