//SN-J00594 张源朔 西安市高新第二初级中学 621123201306230018

#include <bits/stdc++.h>

using namespace std ;

short s[100000000]={} ;
int n ;
long long a,len=1 ;
char c ;

int main() {
	freopen("string.in","r",stdin) ;
	freopen("string.out","w",stdout) ;
	cin>>n ;
	for(int i=1;i<=n;i++) {
		cin>>a>>c ;
		for(int j=1;j<=a;j++) {
			s[len]=c-'a'+1 ;
			len++ ;
		}	
	}
	len-- ;
	int ans=0 ;
	for(int i=1,j=len;i<=len/2;i++,j--) {
		if(s[i]!=s[j]) {
			ans++;
		}		
	}
	cout<<ans ;
	//撒花☆(￣▽￣)/ 
	return 0 ;
} 
