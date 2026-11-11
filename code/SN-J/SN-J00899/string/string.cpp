#include<bits/stdc++.h>
using namespace std;
long int n,a,ans;
int p[1000000000000000],q[1000000000000000];
string S,c;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a>>c;
		for(int i=1; i<=a; i++) {
			S+=c;
		}
	}
	int line=S.size();
	for(int i=0; i<=line-1; i++) {
		p[i]=S[i];
	}
	long int m=0;
	for(int i=line-1; i>=0; i--) {
		q[m]=S[i];
		m+=1;
	}
	for(int i=0; i<=(line-1)/2; i++) {
		if(p[i]!=q[i]) {
			ans+=1;
		}
	}
	cout<<ans;
	return 0;
}
