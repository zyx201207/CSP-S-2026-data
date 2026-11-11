//SN-J00594 张源朔 西安市高新第二初级中学 621123201306230018 

#include <bits/stdc++.h>

using namespace std ;

long long n,m ;
long long a[500010]={} ;

int main() {
	freopen("crystal.in","r",stdin) ;
	freopen("crystal.out","w",stdout) ;
	cin>>n>>m ;
	for(int i=1;i<=n;i++) {
		cin>>a[i] ;
	}
	sort(a+1,a+n+1) ;
	for(int i=1;i<=n;i++){
		m-=(i-1)*(a[i]-a[i-1]) ;
		if(m<0) {
			cout<<(i-1) ;
			break ;
		}
	}
	return 0 ;
}
