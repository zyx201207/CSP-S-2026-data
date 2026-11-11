#include<bits/stdc++.h>
using namespace std;
int n , m , a[500005] , maxx ;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crtstal.out","w",stdout);
	cin >> n >> m ;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i] ;
	}
	for(int i = 1 ; i <= n ; i++){
		int cha[500005] = {} ;
		int ans = m , mj = 0 ;
		for(int j = 1 ; j <= n ; j++){
			cha[j] = abs(a[i] - a[j]) ;
		}
		sort(cha+1,cha+n+1);
		int ji = 1 ;
		while(ans >= 0){
			ans -= cha[ji] ;
			ji++;
			mj++;
		}
		maxx = max(mj,maxx) ;
	}
	cout << maxx - 1 ;
	return 0;
}