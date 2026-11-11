#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen(string.in,"r","in");
	freopen(string.out,"w","out");
	long long n,s=0,z=0,sum=0;
	cin>>n;
	long long a[n];
	char b[n];
	string s1;
	for(long long i=0;i<n;i++){
		cin>>a[i]>>b[i];
		for(long long j=1;j<=a[i];j++){
			s1[s]=b[i];
			s++;
		}
		z=z+a[i];
	}
	long long i=0;
	long long j=z-1;
	while(i<j){
		if(s1[i]!=s1[j]){
			sum++;
		}
		i++;
		j--;
	}
	cout<<sum;
}
