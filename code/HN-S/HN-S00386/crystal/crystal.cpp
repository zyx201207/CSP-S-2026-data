#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 5 * 1e5 + 10; 

ll n,m;
ll a[N];
ll sum;

//int disf (int x){
//	return x >= 10;
//}
//int erfen (int l,int r){
//	int mid =  l + r >> 1;
//	while (l < r){
//		if (disf(mid)){
//			r = mid;
//		}
//		else {
//			l = mid + 1;
//		}
//	}
//	return l;
//}

int main (){
	
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for (int i = 1;i <= n;i++){
		cin>>a[i];
	}
	
	for (int i = 1;i <= n;i++){	
		if ((a[i] == a[i + 1] && a[i + 1] == a[i + 2]) && m < n){
			cout<<m;
			return 0;
		}	
		else {
			cout<<n;
			return 0;
		}	
	}
	
	sort(a + 1,a + 1 + n);
	
	for (int i = 1;i <= m;i++){
		if (a[i + 2] - a[i + 1] == a[i + 1] - a[i]){
			cout<<2;
			return 0;
		}		
	}
	
//	for (int i = 1;i <= m;i++){
//		a[i] += 1;
//	}
//	
//	for (int i = 1;i <= m;i++){
//		sum += a[i];
//	}
//	for (int i = 1;i <= n;i++){
//		erfen(a[i],);
//	}
//	
	cout<<sum;
	
	return 0;
}
