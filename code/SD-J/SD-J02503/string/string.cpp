#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
ll a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n,cnt=0,w1=0,w2=0,ans=0;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		cnt+=a[i];
	}
	ll cnt1=cnt/2;
	ll l=1,r=n;
	while(l<=r){
		w1+=a[l],w2+a[r];
		if(a[l]>cnt1)a[l]=w1-cnt1;
		if(a[r]>cnt1)a[r]=w2-cnt1;
		if(a[l]>a[r]){
			if(c[l]!=c[r])ans+=a[r];
			a[l]-=a[r],a[r]=0;
		}
		if(a[l]<=a[r]){
			if(c[l]!=c[r])ans+=a[l];
			a[r]-=a[l],a[l]=0;
		}
		if(a[l]==0)l++;
		if(a[r]==0)r--;
	}
	cout<<ans;
	return 0;
}

