#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
ll n,a[N],c[N],b[N];char ch;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>b[i]>>ch,c[i]=ch-'a'+1;
	for(int i=1;i<=n;++i) a[i]=b[i-1]+1,b[i]+=b[i-1];
	ll L=b[n],ans=0;
	for(int i=1,j=n;i<j;++i){
		ll l=L+1-b[i],r=L+1-a[i];
		while(i<j&&a[j]>r) --j;
		if(i==j) continue;
		while(i<j&&b[j]>=l){
			if(c[i]!=c[j]) ans+=min(b[j],r)-max(a[j],l)+1;
			--j;
		}
		++j;
	}
	cout<<ans;
	return 0;
}
