#include<bits/stdc++.h>
using namespace std;
long long n;
string js="";
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		long long a;
		string b;
		cin>>a>>b;
		for(int i=1; i<=a; i++) {
			js+=b;
		}
	}
	string ts=js;
	long long sum=0;
	reverse(ts.begin(),ts.end());
	if(js==ts) {
		cout<<0;
		return 0;
	} else {
		for(int i=1; i<=js.size(); i++) {
			if(js[i]!=ts[i]) {
				sum++;
				ts[i]=js[i];
			} else {
				continue;
			}
		}
	}
	cout<<sum;
	return 0;
}
