#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
typedef long long ll;
int n,ans;
ll m,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m; 
	queue<int>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int sz=0;
	ll lst=0;
	for(int i=1;i<=n;i++){
		ll tmp=lst+(a[i]-a[i-1])*(ll)sz;
		while(sz&&tmp>m){
			int t=q.front();q.pop();
			sz--;
			tmp-=a[i]-t;
		}
		q.push(a[i]);
		sz++;
		ans=max(ans,sz);
		lst=tmp;
	}
	cout<<ans;
	return 0;
}
