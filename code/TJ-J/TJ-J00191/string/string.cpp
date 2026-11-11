#include<bits/stdc++.h>
using namespace std;
int main(){ 
	long long n;
	cin >> n;
	long long a[100001];
	string c,s;
	string c1;
	for(int i=0;i<n;i++){
		cin >> a[i] >> c[i];
		for(int j=0;j<a[i];j++){
			c1[j]=c[i];
		}
	}
	int len = c1.size();
	int sum=0;
	for(int i=0;i<len/2;i++){
		s[i]=c1[i];
	}
	int clen = c.size();
	int slen = s.size();
	int j=slen;
	for(int i=len/2-1;i<clen;i++){
		if(c1[i]!=s[j]){
			sum++;
		}
		j--;
	}
	cout << sum;
	return 0;
}
