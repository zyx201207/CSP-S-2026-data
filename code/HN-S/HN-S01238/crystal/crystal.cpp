#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500100],ans,d[500100];
int main(){
	freopen("crystal4.in","r",stdin);
	freopen("crystal4.out","w",stdout);	
	cin >> n >> m ;
	for(int i=1;i<=n;i++){
		cin >> a[i];
//		d[i]=d[i-1]+a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		d[i]=d[i-1]+a[i];
	}
//	for(int i=1;i<=n;i++){
//		long long k=m,cnt=1;
//		for(int j=1;j<i;j++){
//			if(k>=a[i]-a[j]){
//				k-=(a[j]-a[i]);
//				cnt++;
//			}
//			
//		}
//		ans=max(ans,cnt);
//	}
	for(int i=1;i<=n;i++){
		long long p=i;
		if(p*a[i]-d[i] <= m)ans=p;
	}
	cout << ans;
	return 0 ;
} 
/*
5 8
-3 -1 2 2 7

*/
