#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans=1,jl,lans,zans=INT_MIN,dt;
bool check(int k){
	int mb=a[k],lm=m;
	for(int i=1;i<k;i++) lm-=(mb-a[i]);
	jl=lm;
	return (lm>=0?1:0); 
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int l=0,r=n;
	while(l+1<r){
		int mid=(l+r)/2;
		if(check(mid)) ans=mid,l=mid;
		else r=mid; 
	}
	check(ans);
	dt=ans;
	zans=ans;
	m=jl;
	for(int i=1;i<=dt&&dt<=n;){
//		if((dt-i+1)==312414) cout<<dt<<" ";
		zans=max(zans,(dt-i+1));
		if(a[dt+1]==a[dt]){
			dt++;
			continue;
		}
		if(m>=(a[dt+1]-a[dt])*(dt-i+1)){
			m-=(a[dt+1]-a[dt])*(dt-i+1);
			dt++;
			continue;
		}		
		m+=a[dt]-a[i];
		i++;
		lans--;
	}
	cout<<zans;
	return 0;
} 
