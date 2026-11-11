#include<bits/stdc++.h>
using namespace std;
long long n,m;
const long long maxn=5e5+7;
long long a[maxn];
long long ans;
deque<long long>q;
int main(){
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	long long num=0,cnt=1;
	for(long long i=1;i<=n;i++){
		if(i==1){
			q.push_back(a[i]);
			continue;
		}
		num+=q.size()*(a[i]-q.back());
		cnt++;
		while(num>m){
			cnt--;
			num-=a[i]-q.front();
			q.pop_front();
		}
		ans=max(ans,cnt);
		q.push_back(a[i]);
	}
	printf("%lld",ans);
	return 0;
}
