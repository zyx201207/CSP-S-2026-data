#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long a[500005];
long long ans=1;
long long k=1;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	while(m >= 0){
		if((a[k+1] - a[k])*ans <= m){
			m -= (a[k+1]-a[k])*ans;
			a[k] = a[k+1];
			ans++;
		}
		else{
			cout << ans;
			return 0;
		}
		k++;
		//cout << m;
	}
	return 0;
}
