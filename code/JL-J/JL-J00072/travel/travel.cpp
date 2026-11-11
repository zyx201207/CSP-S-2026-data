#include <bits/stdc++.h>
using namespace std;
long long a,b;
string a2,b2;
long long p1,p2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> a >> a2 >> b >> b2;
	if (a==b){
		cout << 1;
	}
	else{
		cout << "0000";
		return 0;
	}
	p1=(long long)(a2[0]-'0')*10;
	p1+=(long long)(a2[1]-'0');
	p2=(long long)(b2[0]-'0')*10;
	p2+=(long long)(b2[1]-'0');
	if (p1==p2){
		cout << 1;
	}
	else{
		cout << "000";
		return 0;
	}
	long long xz1=(long long)(a2[2]-'A');
	long long xz2=(long long)(b2[2]-'A');
	if ((xz1<=2 && xz2<=2) || (xz1>2 && xz2>2)){
		cout << 1;
	}
	else{
		cout << "00";
		return 0;
	}
	if (abs(xz1-xz2)==1){
		cout << 1;
	}
	else{
		cout << 0;
	}
	return 0;
}