#include <bits/stdc++.h>
using namespace std;


long long n ,m;
long long a[500005];

bool cmp(long long a,long long b){
	return a<b;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	
	cin >>n>> m;
		for(int i = 1; i<=n; i++){
			cin >>a[i];
		}
		sort(a+1,a+n+1,cmp);
		for(int i = 1; i<=n; i++){
			a[i] = a[i+1]-a[i];
		}
		for(int i = 1; i<=n; i++){
			a[i] = a[i-1]+a[i]*i;
		}

		long long ans = 0; 
		for(int i = 1; i<n; i++){
			if(m>=a[i])
			{
				ans = i;
			}
		}
		cout << ans+1 ;
	
	return 0;
}
