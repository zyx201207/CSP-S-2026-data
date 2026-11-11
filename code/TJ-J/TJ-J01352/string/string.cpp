#include <bits/stdc++.h>
using namespace std ;
long long n,sum=0 ;
string da1,da2 ;
struct zfc{
    int jg ;
    string zf ;
    string pg ;
};
int main(){
	freopen("string.in","r",stdin) ;
	freopen("string.out","w",stdout) ; 
	cin>>n ;
	zfc a[n+5] ;
	for(int i=0 ;i<n ;i++){
	    cin>>a[i].jg>>a[i].zf ;
	    for(int j=0 ;j<a[i].jg ;j++) a[i].pg+=a[i].zf ;
    }
    for(int i=0 ;i<n ;i++) da1+=a[i].pg ;
    for(int i=ceil(da1.size()/2.0) ;i<da1.size() ;i++){
    	da2+=da1[da1.size()-i-1] ;
	}
    for(int i=0 ;i<ceil(da1.size()/2.0) ;i++){
    	if(da2[i]!=da1[i+ceil(da1.size()/2.0)]) sum++ ;
	}
	cout<<sum ;
}
