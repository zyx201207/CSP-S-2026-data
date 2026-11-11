#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
long long n,m,x,y;
long long l1,l2;
char a,b;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	n=(c1[0]-'0')*10+(c1[1]-'0');
	m=(c2[0]-'0')*10+(c2[1]-'0');
	a=s1[2];
	b=s2[2];
	x=(s1[0]-'0')*10+(s1[1]-'0');
	y=(s2[0]-'0')*10+(s2[1]-'0');
	if(n!=m) {
		cout<<"0000"<<endl;
	} else {
		cout<<"1";
		if(x!=y) {
			cout<<"000"<<endl;
		} else {
			cout<<"1";
			if((a>='A'&&a<='C'&&b>='A'&&b<='C')) {
				cout<<"1";
				if(abs((a-'A')-(b-'A'))==1) {
					cout<<"1";
				} else {
					cout<<"0";
				}
				cout<<endl;
			} else if((a>='D'&&a<='F'&&b>='D'&&b<='F')) {
				cout<<"1";
				if((a=='D'&&b=='F')||(b=='D'&&a=='F')) {
					cout<<"1"<<endl;
				} else {
					cout<<"0"<<endl;
				}
				cout<<endl;
			} else {
				cout<<"00"<<endl;
			}
		}
	}
	return 0;
}
