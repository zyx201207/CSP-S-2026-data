#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,ans;
long long a[N],sum[N],m;
bool cmp(long long a,long long b){
	return a<b;
}
queue<int> q;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	q.push(1);
	for(int i=1;i<=n;i++){
		while(q.size()&&(a[i]*(i-q.front()+1)-(sum[i]-sum[q.front()-1]))>m) q.pop();
		ans=max(ans,i-q.front()+1);
		q.push(i);
	}
	printf("%d",ans);
	return 0;
}