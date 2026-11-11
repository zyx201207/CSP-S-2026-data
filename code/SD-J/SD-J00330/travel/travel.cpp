#include<bits/stdc++.h>
using namespace std;
int a1,a2;
string s1,s2;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>s1>>a2>>s2;
	char x1=s1[0],x2=s1[1],y1=s2[0],y2=s2[1];
	char c1=s1[2],c2=s2[2];
	if(a1==a2) {
		cout<<1;
		if(x1==y1&&x2==y2) {
			cout<<1;
			if(c1=='D'&&c2=='F'||c1=='F'&&c2=='D') {
				cout<<1<<1;
			} else if(c1=='A'&&c2=='B'||c1=='B'&&c2=='A') {
				cout<<1<<1;
			} else if(c1=='C'&&c2=='B'||c1=='B'&&c2=='C') {
				cout<<1<<1;
			} else if(c1=='C'&&c2=='A'||c1=='A'&&c2=='C') {
				cout<<1<<0;
			} else {
				cout<<0<<0;
			}
		} else {
			cout<<0<<0<<0;
		}
	} else {
		cout<<0<<0<<0<<0;
	}
	return 0;
}
