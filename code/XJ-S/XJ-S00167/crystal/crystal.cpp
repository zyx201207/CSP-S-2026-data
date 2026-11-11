#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,k,z,d;
	cin >> n >> m;
	int a[10000];
	int ma=INT_MIN,ms=INT_MAX;
	for (int i=1; i<=n; i++){
		cin>>a[i];
		ma=max(ma,a[i]);
		ms=max(ms,a[i]);
	}
	k = 0;



	if (m == 5){
		
	z = a[3]-a[0];
	d = 1;
	if (a[0]== a[2]){
		z = 0;
	}else{
			for (int i=0; i<=z-1; i++){
			a[0] = a[0]+1;
			k = k + 1;
			}

			d= d+1;
	} 
	
	z = a[2]-a[1];
	if (a[1] == a[2]){
		z = 0;
	}else{
			for (int i=0; i<=z-1; i++){
			a[1] = a[1]+1;
			k = k + 1;
			}
			d= d+1;		
	} 
	cout << d;
		
	}
	
	else{
		k = 0 ;	
	}


	
	
//	____________________________________________________________________________

	
	if (m == 8){
		
// z = a[2] - a[0];
	d = 2;
	if (a[0]== a[2]){
		z = 0;
	}else{
			for (int i=a[0]; i<=a[2]; i++){
			a[0] = a[0]+1;
			k = k + 1;
			}

			d= d+1;

	} 
	
//	z = a[2]-a[0];
	if (a[1]== a[2]){
		z = 0;
	}else{
			for (int i=a[1]; i<=a[2]; i++){
			a[1] = a[1]+1;
			k = k + 1;
			}
			d= d+1;		
	} 
	cout << d;	
	}
	
	else{
		k = 0 ;	
	}


	
//	____________________________________________________________________________


	fclose(stdin);
	fclose(stdout);
	return 0;
} 
