#include<bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("string.in","r",stfin);
	//freopon("string.out","w",stdout);
	int n;
	cin>> n;
	int b=0; 
	int a[n];
	for(int i=1;i<=n;i++){
		cin>> a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=a[n-i]){
			b++;
		}
	}
	cout << b;
	return 0;
}
