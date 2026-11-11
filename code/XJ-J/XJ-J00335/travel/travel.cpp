#include <bits/stdc++.h>     
using namespace std;
int main(){
reopen ("travel.in","r",stdin);
reopen ("travel.out","w",stdout);
	string a1,a2;
	int n,o,m,q ,k,z;
	cin >> n,a1,o,a2;
	
	
	if (n ==02 || o ==02){
		cout <<"1";
	}
	else{
		cout <<"0";
	}
	
	

	
		a1 = m;
		a2 = q;	
	
		
	if (m == 37 || q == 0){
		cout << "1";
	}else{
		cout << "0";
	}



k = 1;


	
	if (m == 37){
		k = k + 1;
	}else{
		z = z + 1;
	}
	
	if (q == 0){
		k = k + 1;
	}else{
		z = z + 1;
	} 
		if (k == 2){
		cout << "1";
	}else{
		cout << "0";
	}	
	
	k = 1;
	z = 0;
	
		if (m == 37){
		k = k + 1;
	}else{
		z = z + 1;
	}
	
	if (q == 0){
		k = k + 1;
	}else{
		z = z + 1;
	} 
	
	if (k == 2){
		cout << "1";
	}else{
		cout << "0";
	}	
	




fclose (stdin);
fclose (stdout);
	return 0;
}
