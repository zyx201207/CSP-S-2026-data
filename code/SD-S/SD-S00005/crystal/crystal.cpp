#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
int n,m;
ll a[N];
ll suf[N],fus[N];
bool cmp(int a,int b){
	return a>b;
}
ll s[N];
ll ma=-1;
int t[325];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(a[i],ma);
	}
	sort(a+1,a+n+1);
	suf[2]=a[2]-a[1];
	for(int i=3;i<=n;i++){
		suf[i]=suf[i-1]+((i-1)*(a[i]-a[i-1]));
	}
	ll sop=upper_bound(suf+1,suf+n+1,m)-suf;
	while(suf[sop]>m)sop--;
	ll ans=sop;
	if(n>5000&&ma<=100){
		for(int i=1;i<=n;i++){
			t[a[i]+101]++;
		}
		int cnt=0;
		for(int i=2;i<=n;i+=t[++cnt]){
			int tot=0;
			for(int j=i+1;j<=n;j++){
				s[++tot]=suf[j]-suf[i];
			}
			ll pos=upper_bound(s+1,s+tot+1,m)-s;
			while(s[pos]>m)pos--;
			ans=max(ans,pos);
		}
		cout<<ans;
		return 0;
	}
	if(n<=10000){
		for(int i=2;i<=n;i++){
			int tot=0;
			for(int j=i+1;j<=n;j++){
				s[++tot]=suf[j]-suf[i];
			}
			ll pos=upper_bound(s+1,s+tot+1,m)-s;
			while(s[pos]>m)pos--;
			ans=max(ans,pos);
		}
	}
	cout<<ans;
	return 0;
}
