#include <bits/stdc++.h>
using namespace std;
long long n;
int a[200001];
string c[200001];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			s+=c[i];
		}
	}
	int c=0,m=s.size();
	for(int i=0;i<m/2;i++){
		if(s[i]!=s[m-i-1]){
			c++;
		}
	}
	cout<<c;
	return 0;
}
