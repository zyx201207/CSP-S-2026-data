#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,d,e;
	char c,f;
	cin>>a>>b>>c>>d>>e>>f;
	if(a==d) {
		cout<<1;
		if(b==e) {
			cout<<1;
			if((c>='A'&&c<='C'&&f>='A'&&f<='C')||(c>='D'&&c<='F'&&f>='D'&&f<='F')) {
				cout<<1;
				if((int)abs(c-f)==1)cout<<1;
				else cout<<0;
			}
			else cout<<0<<0;
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	return 0;
}
