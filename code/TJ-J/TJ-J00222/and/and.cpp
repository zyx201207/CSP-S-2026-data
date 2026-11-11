#include<bits/stdc++.h>

using namespace std;

#define int long long

int n,m,a[1000005],cnt,o;

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	if(n == m){
		cnt = a[1];
		for(int i = 2;i <= n;i++){
			cnt = cnt & a[i];
		}cout<<cnt;
		return 0;
	}
	if(m == 1){
		for(int i = 1;i <= n;i++){
			o = max(a[i],o);
		}cout<<o;
		return 0;
	}
	if(m == 2){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(i == j){
					continue;
				}
				o = max(o,(a[i] & a[j]));
			}
		}cout<<o;
		return 0;
	}sort(a + 1,a + n + 1);
	o = a[n];
	for(int i = n-1;i > n - m;i--){
		o = o & a[i];
	}
	return 0;
}
