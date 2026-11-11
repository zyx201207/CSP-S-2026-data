#include <bits/stdc++.h>
using namespace std;
int n;
string s,s2,s1;
long long int num;
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long int a;
		char c;
		cin>>a>>c;
		num+=a;
		for(long long int j=1;j<=a;j++){
			s+=c;
		}
	}
	long long int op=0;
	for(long long int i=0,j=num-1;i<num/2;i++,j--){
		if(s[i]!=s[j]){
			op++;
		}
	}
	cout<<op;
	return 0;
}