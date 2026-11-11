#include<bits/stdc++.h>
using namespace std;
int n1,n2;
int m1,m2;
int i1,i2;
string s1,s2;
int to_i(char c) {
	switch(c) {
		case 'A':
			return 1;
		case 'B':
			return 2;
		case 'C':
			return 3;
		case 'D':
			return 5;
		case 'F':
			return 6;
	}
	return -1;
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n1>>s1>>n2>>s2;
	m1=(s1[0]-'0')*10+(s1[1]-'0');
	m2=(s2[0]-'0')*10+(s2[1]-'0');
	i1=to_i(s1[2]);
	i2=to_i(s2[2]);
	if(i1>i2) {
		swap(i1,i2);
	}
	if(n1!=n2) {
		cout<<"0000"<<endl;
		return 0;
	}
	if(m1!=m2) {
		cout<<"1000"<<endl;
		return 0;
	}
	if(i1<=3 && i2>=5) {
		cout<<"1100"<<endl;
		return 0;
	}
	if(i2-i1!=1) {
		cout<<"1110"<<endl;
		return 0;
	}
	cout<<"1111"<<endl;
	return 0;
}