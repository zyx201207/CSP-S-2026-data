#include<bits/stdc++.h>
using namespace std ;
long long n , d , ans ;
long long land[2000010] ;
int usb=0 ;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c , t ;
	cin >> c >> t ;
	while(t--){
		cin >> n >> d ;
		ans=0 ;
		for(int i=1;i<=n;i++)cin >> land[i] ;
		for(int gl=1;gl<n-2;gl++){
			for(int fr=n;fr>gl+2;fr--){
				if(land[fr]-land[gl]>=d*2||land[fr]-land[gl]<=d)continue;
				long long num=0 ;
				for(int il=gl+1;il<fr-1;il++){
					if(land[fr]-land[il]>d||land[il]-land[gl]>=d)continue;
					for(int bl=il+1;bl<fr;bl++){
						if(land[fr]-land[bl]>=d||land[bl]-land[gl]>d)continue;
						ans++ ;
						num++ ;
					}
				}
				if(num==2)ans-- ;
				if(num>=3)ans -= num ;
			}
		}
		cout << ans << "\n" ;
	}
	return 0;
}
