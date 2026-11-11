#include <bits/stdc++.h>
using namespace std; 
long long n , m , a[500005] , s , ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n>> m;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
	}
	sort(a,a+n);
	while(m>=s){
		s=a[ans+1]-a[ans];
		if(m>=s) {
			if(ans+1<n){
				ans ++;
				m-=ans*s;
			}else if(ans+1 == n){
				break;
			}
		}else{
			break;
		}
	}
	for(int i= ans; i < n; i ++){
		if(a[i] == a[ans]&&i!=ans)ans++;
	}
	cout << ans+1;
	return 0;
}
