#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a,sum=0,j=0,gj=0;
	string e,b;
	cin>>n;
	while(n--){
		cin >> a;
		cin >> e;
		for(int i=0;i<a;i++){
			b=b+e;
		}
		sum+=a;
	}
	for(int i=0;i<sum/2;i++){
		if(b[i]!=b[sum-i-1]){
			gj++;
		}
	}
	cout << gj;
	return 0;
} 
