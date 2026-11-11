#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500005;
ll n,a[N],ans,m,cnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	deque<ll> q;
	q.push_back(a[1]);
	for(int i=2;i<=n;i++){
		ll t=a[i]-q.back();
		if(cnt+q.size()*t<=m){
			cnt+=q.size()*t;
			q.push_back(a[i]);
		}else{
			int t2=q.size();
			while(cnt+t2*t>m&&q.size()>0){
				cnt-=(q.back()-q.front());
				t2--;
				q.pop_front();
			}
			cnt+=t2*t;
			q.push_back(a[i]);
		}
		ans=max(ans,(long long)q.size());
	}
	printf("%lld",ans);
	return 0;
} 
/*
5 8
-3 -1 2 2 7
*/
