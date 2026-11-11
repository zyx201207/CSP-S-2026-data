#include <bits/stdc++.h>
using namespace std;
long long n , m , a[500005] ,  b[500005] , x , y , c;
int main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	cin >> n >> m; 
	for(int i=1 ; i<=n ; i++){
		cin>>a[i];
	}
	sort(a+1 , a+n+1);
    for(int i=1 ; i<=n ; i++){
    	b[i]=b[i-1]+a[i];
	}
	for(int i=2 ; i<=n ; i++){
    	x=(a[i]*i)-b[i];
    	if(x==m){
    	   y=i;
    	   break;
		}
	}	
	for(int i=1 ; i<=n ; i++){
		if(a[i]==a[y]){
		   c++;	
		}
	}
	cout << y+c-1;
	return 0;
} 
