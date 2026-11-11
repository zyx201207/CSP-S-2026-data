#include<bits/stdc++.h>
using namespace std ;
int n , t , h ;
int why[200010] ;
char lyc[200010] ;
long long ans=0 ;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n ;
	if(n==1){
		cout << 0 ;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin >> why[i] >> lyc[i] ;
	}
	t = 1 ;
	h = n ;
	while(t<h){
		int zym = min(why[t],why[h]) ;
		if(lyc[t]!=lyc[h]){
			ans += zym ;
		}
		why[t] -= zym ;
		why[h] -= zym ;
		if(why[t]==0)t++ ;
		if(why[h]==0)h-- ;
	}
	cout << ans ;
	return 0;
}
