#include<bits/stdc++.h>
using namespace std;
long long n,s[200005],cnt;
char z[200005];
string b;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>s[i]>>z[i];
		for(int j=0;j<s[i];j++) {
			b+=z[i];
		}
	}
	for(int i=0;i<b.size()/2;i++) {
		if(b[i]!=b[b.size()-i-1]) cnt++;
	}
	cout<<cnt;
	return 0;
}