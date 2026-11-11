#include<bits/stdc++.h>
using namespace std;
int g[500009];
int q[500009],hh=0,tt=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>g[i];
	}
	sort(g+1,g+1+n);
	int ans=0;
	long long sum=0;
	int cnt=0;
	for(int i=1;i<=n;i++){
		sum+=cnt*(g[i]-g[i-1]);
		while(hh<=tt&&sum>m){
			sum-=g[i]-g[q[hh]];
			cnt--;
			hh++;
		}
		q[++tt]=i;
		cnt++;
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
