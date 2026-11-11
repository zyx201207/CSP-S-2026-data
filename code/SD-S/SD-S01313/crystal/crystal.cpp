#include<bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef pair<int,int> pii;
const int _MAXn=5e5+100;

int n;
i64 m;
i64 num[_MAXn],sum[_MAXn];
int ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&num[i]);
	}
	sort(num+1,num+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+num[i]; 
	}
	for(int i=1,p=0;i<=n;i++){
		while(num[i]*p-sum[p]<num[i]*i-sum[i]-m)p++;
		ans=max(ans,i-p);
	}
	printf("%d\n",ans);
	return 0;
}
//(val[i]*i-sum[i])-m<=(val[i]*p-sum[p])
