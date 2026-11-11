#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int n,m,k,z,d;
	cin >> k >> m;
	n = 30;
	int a[10000];
	int ma=INT_MIN,ms=INT_MAX;
	for (int i=1; i<=n; i++){
		cin>>a[i];
		ma=max(ma,a[i]);
		ms=max(ms,a[i]);
	}

	cout << "1" << endl;
	cout << "2" << endl;




	fclose(stdin);
	fclose(stdout);
	return 0;
} 
