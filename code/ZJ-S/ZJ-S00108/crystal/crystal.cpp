#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=5e5+6;
int ans=0;
int used=0;
int a[N];
int d[N];
deque<int> q;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		d[i]=a[i]-a[i-1];
	}
	for(int i=1;i<=n;i++){
		used+=d[i]*q.size();
		q.push_back(a[i]);
		while(used>m){
			int x=q.front();
			used-=a[i]-x;
			q.pop_front();
		}
		if(q.size()>ans){
			ans=q.size();
		}
	}
	printf("%lld",ans);
	return 0;
}
