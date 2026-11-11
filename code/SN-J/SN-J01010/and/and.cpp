#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long a,b;
	long long x[200001];
	cin >> a >> b;
	for (long long i = 1 ;i <= a ;i++)
		cin >> x[i];
	for (long long i = 1 ;i <= a-1 ;i++){
		for (long long j = i ;j <= a ;j++){
			if(x[j] >= x[i]){
				int g= x[i];
				x[i]=x[j];
				x[j]=g;
			}
	}
	}
	long long n=x[1];
	for ( long long i = 2 ;i <= b ;i++){
		n=n&x[i];
	}
	cout << n;
	return 0;	
}
	
	
	
