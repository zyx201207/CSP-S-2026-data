#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define S second
#define F first
const ll N=1e6+5,mod=1e9+7,inf=1e18;
ll n,a[N],b[N],ans,len;
char s[N];
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		len+=a[i];
		b[i]=b[i-1]+a[i];
	}
	ll l=1,r=b[n],l1=1,r1=n;
	while(l<=r){
		if(s[l1]!=s[r1]) ans+=min(a[l1],a[r1]);
		l+=min(a[l1],a[r1]);
		r-=min(a[l1],a[r1]);
		if(a[l1]<a[r1]) a[r1]-=a[l1],l1++;
		else a[l1]-=a[r1],r1--;
	}
	cout<<ans;
	return 0;
}

