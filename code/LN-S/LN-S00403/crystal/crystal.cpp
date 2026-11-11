#include <bits/stdc++.h>
using namespace std ;
int main (  ) { 
	long long n,m,a[500000],jz=0,p=0,q=0 ;
	cin >> n >> m ;
	for ( int i=0 ; i<n ; i++ ) { 
		cin >> a[i] ;
	} for ( int i=0 ; i<n ; i++ ) { 
		for ( int j=0 ; j<n ; j++ ) { 
			if ( a[i] < a[j] ) { 
				int t=a[i] ;
				a[i]=a[j] ;
				a[j]=t ;
			} 
		} 
	} 
	if ( n%2==0 ) jz=n/2 ;
	else jz=(n-1)/2 ;
	for ( int i=jz ; i>=0 ; i-- ) { 
		p+=a[jz]-a[i] ;
		if ( p>m ) {
			p-=i ;
			break ;
		} else {
			q++ ;
		}
	} 
	for ( int i=jz+1 ; i<n ; i++ ) { 
		if ( a[i] != a[jz] ) break ;
		else q++ ;
	}
	cout << q ;
	return 0 ;
} 
