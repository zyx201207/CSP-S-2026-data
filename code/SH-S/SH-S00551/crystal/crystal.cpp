#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans=1;
deque<int> q;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	int k=1,w=0,now=1;
	q.push_back(a[1]);
	while(!q.empty()){
		while(w<=m&&(!q.empty())&&now<=n){
			q.push_back(a[++now]);			
			w+=k*(a[now]-a[now-1]);
			k++;
			if(w<=m&&k<=n&&now<=n){
				ans=max(ans,k);
			}
		}
		if(now>=n){
			break;
		}
		while(w>m&&(!q.empty())){
			w-=(a[now]-q.front());
			q.pop_front();
			k--;
		}
		if(k<=n&&now<=n) ans=max(ans,k);
		if(now>=n){
			break;
		}
	}
	ans=min(ans,n);
	printf("%lld",ans);
	return 0;
}
