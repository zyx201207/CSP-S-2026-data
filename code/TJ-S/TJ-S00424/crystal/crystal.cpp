#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],ans,pos;
bool check(int x){
	int cnt=0;
	for(int i=0;i<n;i++){
		if(a[i]<x)cnt+=x-a[i];
	}
	if(cnt<=m)return 1;
	else return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int l=1e12,r=-1e12;
	for(int i=0;i<n;i++){
		cin>>a[i];
		l=min(l,a[i]);
		r=max(r,a[i]);
	}
	//cout<<l<<' '<<r<<'\n';
	while(l<=r){
		int mid=(l+r)/2;
		//cout<<mid<<' '<<l<<' '<<r<<' ';
		if(check(mid)){
			pos=mid;
			l=mid+1;
		}
		else r=mid-1;
		//cout<<l<<' '<<r<<' '<<pos<<'\n';
	}
	//cout<<pos<<' ';
	for(int i=0;i<n;i++){
		if(a[i]<=pos)ans++;
	}
	cout<<ans;
	return 0;
}
