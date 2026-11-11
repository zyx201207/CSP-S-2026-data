#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005],n;char c[200005];
vector<int>tmpp;
int cc(int l){
	return c[lower_bound(a+1,a+n+1,l)-a];
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];cin>>c[i];
	}
	for(int i=1;i<=n;i++)a[i]+=a[i-1];
	int ans=0;
	if(a[n]&1){
		int sum=(a[n]+1)/2;
		int bl=0,tmp=0;
		for(int i=1;i<=n;i++){
			if(sum<=a[i]){
				bl=i;break;
			}
		}
		tmpp.push_back(0);
		for(int i=1;i<bl;i++)tmpp.push_back(a[i]);
		for(int i=bl;i<=n;i++)tmpp.push_back(2*sum-(a[i]+1));
		tmpp.push_back(sum);
	}
	else{
		int sum=a[n]/2;
		int bl=0,tmp=0;
		for(int i=1;i<=n;i++){
			if(sum<=a[i]){
				bl=i;break;
			}
		}
		tmpp.push_back(0);
		for(int i=1;i<(sum==a[bl]?bl+1:bl);i++)tmpp.push_back(a[i]);
		for(int i=(sum==a[bl]?bl+1:bl);i<=n;i++)tmpp.push_back(2*sum-(a[i]+1)+1);
		tmpp.push_back(sum);
	}
	sort(tmpp.begin(),tmpp.end());
//	for(int i:tmpp)cout<<i<<'\n';
	int m=unique(tmpp.begin(),tmpp.end())-tmpp.begin();
	for(int i=0;i<m;i++){
		if(cc(tmpp[i]+1)!=cc(a[n]-tmpp[i]))ans+=tmpp[i+1]-tmpp[i];
	}
	cout<<ans<<'\n';
	return 0;
}
//10:37 100pts ~_~
