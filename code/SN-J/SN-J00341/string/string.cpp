#include <bits/stdc++.h>
using namespace std;
	char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin >> n;
	long long a[200010];
	char b[200010];
	for(long long i=0;i<n;i++){
		cin >> a[i];
		cin >> b[i];
	} 
	long long k=0;
	for(long long i=0;i<n;i++){
		for(long long j=0;j<a[i];j++){
			c[k]==b[i];
			k++;
		}
	}
	long long s = 0;
	long long m;
	if(k%2==0){
		s=k/2+1;
		m=k-1;
	}
	else{
		s=k/2+1;
		m=k;
	}
	m--;
	long long num=0;
	for(long long i=s-1;i<k;i++){
		if(i!=m){
			num++;
		}
	}
	cout << num;
	retrun 0;
	
}


