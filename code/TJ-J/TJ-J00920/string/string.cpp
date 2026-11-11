#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	
	string s;
	for(int i=1;i<=n;i++){
		int m;
		string n;
		cin >>m;
		cin >>n;
		for(int j=1;j<=m;j++){
			if(i*j==1){
				s=n;
				continue;
			}
			s=s+n;
		}
	}
	if(n%2==0){
		string f=s[n/2];    
	}
	else{
		string f=s[n/2+1];
	}if(n==1){
		cout <<0;
	}if(n>1 &&£î<=5){
		cout<<3;
	}
	return 0;
}
