#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin >> a >> b >> c >> d;
	long long c1=(a[0]-'0')*10+(a[1]-'0'),c2=(c[0]-'0')*10+(c[1]-'0');
	if(c1==c2){
		cout << 1;
		long long s1=(b[0]-'0')*10+(b[1]-'0'),s2=(d[0]-'0')*10+(d[1]-'0');
		if(s1==s2){
			cout << 1;
			if((b[2]>='A' && b[2]<='C' && d[2]>='A' && d[2]<='C') || (b[2]>='D' && b[2]<='F' && d[2]>='D' && d[2]<='F')){
				cout << 1;
				if((b[2]=='A' && d[2]=='C') || (b[2]=='C' && d[2]=='A')){
					cout << 0;
				}
				else cout << 1;
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else{
		cout << "0000";
	}
	return 0;
}
