#include<bits/stdc++.h>
using namespace std;
int const N=5e5+5;
int n;
long long m;
int ans;
long long sum;
long long a[N];
queue<long long> que;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(sum+1ll*que.size()*(a[i]-a[i-1])>m){
			while(que.size() && sum+1ll*que.size()*(a[i]-a[i-1])>m){
				sum-=(a[i-1]-que.front());
				que.pop();
			}
			if(sum+1ll*que.size()*(a[i]-a[i-1])>m) break;
		}
		sum+=1ll*que.size()*(a[i]-a[i-1]);
		que.push(a[i]);
		ans=max(ans,(int)que.size());
	}
	cout<<ans;
	return 0;
}
