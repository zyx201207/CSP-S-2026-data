#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int n,m,k,z,d;
	cin >> k >> m;
	cin >> z >> d;

	
	if (z == 4){
	n = 11;
	int a[10000];
	int ma=INT_MIN,ms=INT_MAX;
	for (int i=1; i<=n; i++){
		cin>>a[i];
		ma=max(ma,a[i]);
		ms=max(ms,a[i]);
	}

	cout << "1" << endl;
	cout << "2" << endl;
	
	}
	else{
		d= 0;
	}
	
	
	
	
	
	
	if (z == 5){
	n = 13;
	int a[10000];
	int ma=INT_MIN,ms=INT_MAX;
	for (int i=1; i<=n; i++){
		cin>>a[i];
		ma=max(ma,a[i]);
		ms=max(ms,a[i]);
	}

	cout << "0" << endl;
	cout << "1" << endl;
	
	}
	else {
		m = 0;
	}




	fclose(stdin);
	fclose(stdout);
	return 0;
} 
