#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,j[105],m=0;
	string k[105],s[105];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>j[i]>>k[i];
		for(int h=j[i];h<j[i]+j[i]+1;h++){
			s[h]=k[i];
		}
		m+=j[i];
	}
	for(int i=0;i<m;i++){
		cout<<s[i];
	}
	return 0;
}
