#include<bits/stdc++.h>
using namespace std ;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int a , b , c ;
	cin >> a >> b ;
	while(b--){
		int n , k ;
		cin >> n >> k ;
		for(int i=1;i<=(n-1)*2;i++)cin >> c ;
		cout << k-(n%k) << endl ;
	}
	return 0;
}
