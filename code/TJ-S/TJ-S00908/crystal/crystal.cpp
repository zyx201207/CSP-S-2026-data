#include <bits/stdc++.h>
using namespace std ;
long long n,m,t ;
long long a[600000],cha[600000],as[600000] ;
bool cmp(int x,int y){
	return x>y ;
}
int main(){
freopen("crystal.in","r",stdin); 
freopen("crystal.out","w",stdout);
cin >> n >> m ;
for(int i=1;i<=n;i++){
cin >> a[i] ;
as[i]=1 ;
}
sort(a+1,a+n+1) ;
for(int i=1;i<n;i++) cha[i]=a[i+1]-a[i] ;
for(int i=1;i<n;i++){
	t=m ;
    for(int j=i;j<n;j++){
        if(j+1<=n&&t>=cha[j]*(j-i+1)){
        t-=cha[j]*(j-i+1) ;
        as[i]++ ;
		}
		else break ;
	}
}
sort(as+0,as+n+1,cmp) ;
cout << as[0] ;
return 0 ;
fclose(stdin) ;
fclose(stdout) ;
}
