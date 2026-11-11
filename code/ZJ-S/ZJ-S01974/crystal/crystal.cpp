#include <bits/stdc++.h>
using namespace std;
queue<long long> q;
int n,m,ans;
long long s,a[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i){
		q.push(a[i]);s+=a[i];
		while(!q.empty()&&a[i]*((int)(q.size()))-s>m){
			s-=q.front();
			q.pop();
		}
		ans=max(ans,(int)(q.size()));
	}
	cout<<ans;
	return 0;
}