#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll> pll;
typedef pair<ll,char>plc;
plc a[100010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//	int n;cin>>n;
//	ll sum=0;
//	for(int i=1;i<=n;i++){
//		cin>>a[i].first>>a[i].second;
//		sum+=a[i].first;
//	}
//	ll mid=sum/2+sum%2;
//	ll cntl=1;
//	ll cntr=n; 
//	ll ans=0;
//	ll cha=0;
//	for(int i=1,j=n;cntl<=mid,cntr>=mid;i++,j--){
//		if(a[i].first>a[j].first&&a[i].second!=a[j].second){
//			ans+=a[j].first;
//			cntl+=a[i].first,cntr-=a[j].first;
//			cha=a[i].first-a[j].first;
//			ans+=cha;
//			cntr-=cha;
//		}else{
//			ans+=a[i].first;
//			cntl+=a[i].first,cntr-=a[j].first;
//			cha=a[i].first-a[j].second;
//			ans+=cha;
//			cntr-=cha;
//		}
//	}
//	cout<<ans;
	int n;cin>>n;
	string s;
	ll maxn=-1e9;
	ll sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
		sum+=a[i].first;
		ll num=a[i].first;char c=a[i].second;
		maxn=max(maxn,num);
		for(int i=1;i<=num;i++)s+=c;
	}
	if(maxn*n<=100000000){
		int mid=s.size()/2+(s.size()%2);
		ll ans=0;
		for(int i=0,j=s.size()-1;i<=mid,j>=mid;i++,j--){
			if(s[i]!=s[j])ans++;
		}
		cout<<ans;
	}else{
		ll mid=sum/2+sum%2;
		ll cntl=1;
		ll cntr=n; 
		ll ans=0;
		ll cha=0;
		for(int i=1,j=n;cntl<=mid,cntr>=mid;i++,j--){
			if(a[i].first>a[j].first&&a[i].second!=a[j].second){
				ans+=a[j].first;
				cntl+=a[i].first,cntr-=a[j].first;
				cha=a[i].first-a[j].first;
				ans+=cha;
				cntr-=cha;
			}else{
				ans+=a[i].first;
				cntl+=a[i].first,cntr-=a[j].first;
				cha=a[i].first-a[j].second;
				ans+=cha;
				cntr-=cha;
			}
		}
		cout<<ans;
	}
	return 0;
}
