#include<bits/stdc++.h>
using namespace std;
int s[200010];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,b,cc=0;
	cin>>a>>b;
	for(int i=0; i<a; i++) {
		cin>>s[i];
	}
	if(b==1) {
		for(int i=0; i<a; i++) {
			if(s[i]>cc) {
				cc=s[i];
			}
		}
		cout<<cc;
	}
	return 0;
}
