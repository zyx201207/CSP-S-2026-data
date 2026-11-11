#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,k,ans=0; cin>>n>>k;
	vector<int> a(n),c(n+1,0);
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a.begin(),a.end());
	for(int i=1;i<n;i++) c[i]=a[i]-a[i-1];
	queue<int> q1;
	for(int i=0,l=0,m=k;i<n;i++){
		int cost=0;
		cost=l*c[i];
		if(cost>m){
			while(!q1.empty()&&m<cost){
				m+=a[i-1]-q1.front();
				l--;
				cost-=c[i];
			}
		}
		m-=cost;
		l++; q1.push(a[i]);
		ans=max(ans,l);
	}
	cout<<ans;
	return 0;
}
