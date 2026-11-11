#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long m;
long long a[N],xr[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		xr[i]=a[i]-a[i-1];
	}
	int l=1,r=2;
	int cnt=1,maxs=1;
	long long tot=0ll;
	while(r<=n){
		tot=tot+xr[r]*cnt;
		cnt++;
		while(tot>m){
			cnt--;
			tot-=(a[r]-a[l]);
			l++;
		}
		maxs=max(maxs,cnt);
		r++;
	}
	cout<<maxs;
	return 0;
}