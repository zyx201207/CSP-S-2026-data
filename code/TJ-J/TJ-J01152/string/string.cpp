#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s;
	cin>>n;
	long long a[n];
	char c[n];
	long long num1=0,num2=0;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		for(int j=0;j<a[i];j++){
			s+=c[i];
			num1++;
		}
	}
	for(long long i=0;i<num1/2;i++){
		if(s[i]!=s[num1-i]){
			num2++;
		}
	}
	cout<<num2;
	return 0;
}
