#include<bits/stdc++.h>
using namespace std;
int main() {
 	freopen("string.in","r",stdin);  
  	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string a;
	for(int i=0; i<n; i++) {
		long long  x;
		string y;
		cin>>x>>y;
		for(int j=0;j<x;j++){
			a+=y;
		}
	}
	long long  len=a.size();
	long long  sum=0;
	for(long long i=0; i<len; i++) {
		int num=len-1;
		if(a[i]==a[num] ){
			sum+=0;
		}
		else{
			sum++;
		}
		len--;
	}
	cout<<sum;
	return 0;
}