#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n,m;
ll a[500005],c[500005];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin >> n >> m;

	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}

	sort(a+1,a+n+1);

	for(int i = 1;i <= n;i ++){
		c[i] = a[i] + c[i-1];
	}

	ll ans = 1;

	for(int i = 1;i <= n;i ++){
		/*
		for(int j = 0;j < i;j ++){
			if(c[i] - c[j] + m >= ((i-j)*a[i])){
				ans = max(ans,(ll)i - j);
				break;
			}
		}
		*/
		ll l = 0,r=i-1;
		while(l<=r){
			ll mid = (l+r)>>1;
			if(c[i] - c[mid] + m >= ((i-mid)*a[i])){
				r = mid - 1;
				ans = max(ans,(ll)i-mid);
				//printf("i=%d,mid=%d",i,mid);
			}else{
				l = mid + 1;
			}
		}
	}

	cout << ans << '\n';

	return 0;
}