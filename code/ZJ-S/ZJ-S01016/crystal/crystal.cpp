#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ans,q;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	ans=1;
	for(int i=2;i<=n;i++){
		if(m-ans*(a[i]-a[i-1])>=0){
			m-=ans*(a[i]-a[i-1]);
			ans++;
		}
		else{
			break;
		}
	}
	printf("%lld",ans);
	return 0;
}

