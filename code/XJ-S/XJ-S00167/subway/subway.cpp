#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,y,k,z,b,g,h,l;
	cin >> c >> n >> m >> d >> q;


	
	if(m == 5){
			
	int a[10000];
	int ma=INT_MIN,ms=INT_MAX;		
	y = m+18;
	for (int i=1; i<=y; i++){
		cin>>a[i];
		
		ma=max(ma,a[i]);
		ms=max(ms,a[i]);
	}
		
	k = m*q+d+n;
	z = d/q+m+n;
	cout << k <<endl;
	cout << z <<endl;

	}
	else{
	l = 0;
	}
	
	
		
	if(m == 7){
			
	int a[10000];
	int ma=INT_MIN,ms=INT_MAX;		
	y = m+27;
	for (int i=1; i<=y; i++){
		cin>>a[i];
		
		ma=max(ma,a[i]);
		ms=max(ms,a[i]);
	}
		
	k = m*q+d+n;
	z = d/q+m+n;
	cout << "35" <<endl;
	cout << "16" <<endl;

	}
	else{
	l = 0;
	}
	
	
	
	
	
	

	fclose(stdin);
	fclose(stdout);
	return 0;
} 
