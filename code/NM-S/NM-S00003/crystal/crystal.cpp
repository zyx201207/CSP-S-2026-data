#include<bits/stdc++.h>
using namespace std;
using ll= long long;
const int N = 5e4+5;
ll zd=-0x3f3f3f3f;
ll n,m,a[N],z[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int i=1;
	for(;i<=n;i++){
		cin>>a[i];
	}
	for(i=1;i<=n;i++){
		z[i]=z[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++){
		ll d=(z[i]+m)/i;
		if(d*i!=z[i]+m){
			continue;
		}
		ll f=0,h=0;
		for(int j=i;j>=1;j--){
			f+=abs(d-a[j]);
			if(f>m){
				h=-0x3f3f3f3f;
				break;
			}
			h++;
		}
		zd=max(zd,h);
	}
	cout<<zd;
	return 0;
}
