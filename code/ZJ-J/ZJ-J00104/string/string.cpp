#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int n;
ll a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	ll ans=0;
	ll L=1,R=a[n];
	for(int i=1,j=n;i<j||i==j&&L<R;){
		ll mn=min(a[i]-L+1,R);
		if(c[i]!=c[j])ans+=mn;
		L+=mn,R-=mn;
		if(L>a[i])i++,L=1;
		if(R<1)j--,R=a[j];
	}
	cout<<ans;
	return 0;
}