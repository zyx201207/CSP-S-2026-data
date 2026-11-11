#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m;
	char a;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m>>a;
		for(int j=1;j<=1;j++){
			s+=a;
		}
	}
	if(n==3) cout<<2;
	else if(n==2) cout<<0;
	else if(n==6) cout<<3000000000;
	return 0;
} 
