#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,n1;
	cin>>n;
	string a,b;
	for(long long i=0;i<n;i++){
		cin>>n1>>b;
		for(int j=0;j<n1;j++){
			a+=b;
		}
	}
	string c;
	double n2;
	n2=floor(a.size()/2);
	for(long long i=0;i<n2;i++){
		c+=a[i];
	}
	int n_2=0;
	string aa;
	for(long long i=a.size()-1;i>=n2;i--){
		aa+=a[i];
	}
	for(long long i=0;i<n2;i++){
		if(c[i]!=aa[i]) n_2+=1;
	}
	cout<<n_2;
	return 0;
}
