#include <bits/stdc++.h>
using namespace std;

int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
	string s;
	int n,a;
	long long l=0,ci=0;
	char c;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a>>c;
		for (int j=0 ;j<a;j++){
			s+=c;
			l++;
		}
			
	}
	string neww;
	for (int i=l-1;i>=0;i--){
		neww+=s[i];
	}
	if (neww==s){
		cout<<0;
		return 0;
	}
		for (int i=0;i<l/2;i++){
		if (s[i]!=neww[i]){
			ci++;
		}
			
		}
		
		
	cout<<ci;
	return 0;
	
}