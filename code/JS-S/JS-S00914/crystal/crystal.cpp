#include<bits/stdc++.h>
using namespace std;
int n,p=1,ans;
long long m,x[500009],now;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",x+i);
	sort(x+1,x+n+1);
	for(int i=1;i<=n;i++){
		if(i>1)now+=(x[i]-x[i-1])*(i-p);
		while(p<i&&now>m){
			now-=(x[i]-x[p]),p++;
		}
		ans=max(ans,i-p+1);
	}
	printf("%d\n",ans);
}