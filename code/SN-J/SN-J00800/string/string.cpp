#include <bits/stdc++.h>
using namespace std;
long long n,a[100000],l;
int main(){
	ios::sync_with_stdio(false);
	string c,s;
	cin>>n;
	for(int i=0;i<n;i++){
			cin>>a[i];
		cin>>c[i];
		}
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			s+=c[i];
		}
	}
	l=s.length();
	for(int i=0;i<l;i++){
		if(s[i]!=s[l+1-i]){
			cout<<l-1-i;
		}
		}
		cout<<0;
	return 0;
}
