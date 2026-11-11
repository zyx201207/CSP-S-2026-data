#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long c1/*R³µÏáºÅ*/, s1/*RÅÅºÅ*/, c2/*X³µÏáºÅ*/, s2/*XÅÅºÅ*/;
char z1/*R×ùÎ»ºÅ*/, z2/*X×ùÎ»ºÅ*/;
int main()
{
	//freopen("travel.in","r","stdin");
	//freopen("travel.out","w","stdout");
	cin >> c1 >> s1 >> z1 >> c2 >> s2 >> z2;
	//cout << c1 << ' ' << s1 << ' ' << z1 << ' ' << c2 << ' ' << s2 << ' ' << z2 << endl;
	if(c1 == c2){
		cout << '1';
	} else {
		cout << "0000";
		return 0;
	}
	if(s1 == s2){
		cout << '1';
	} else {
		cout << "000";
		return 0;
	}
	if(z1 == 'A'){
		if((z2 == 'B') || (z2 == 'C')){
			cout << '1';
		} else {
			cout << "00";
			return 0;
		}
	}
	if(z1 == 'B'){
		if((z2 == 'A') || (z2 == 'C')){
			cout << "11";
			return 0;
		} else {
			cout << "00";
			return 0;
		}
	}
	if(z1 == 'C'){
		if((z2 == 'A') || (z2 == 'B')){
			cout << '1';
		} else {
			cout << "00";
			return 0;
		}
	}
	if (z1 == 'D'){
		if((z1 =='D') && (z2 == 'F')){
			cout << "11";
			return 0;
		} else {
			cout << "00";
			return 0;
		}	
	}
	if(z1 == 'F'){
		if((z1 =='F') && (z2 == 'D')){
			cout << "11";
			return 0;
		} else {
			cout << "00";
			return 0;
		}	
	}
	if((z1 == 'A') && (z2 == 'B')){
		cout << '1';
		return 0;
	} else {
		cout << '0';
		return 0;
	}
	if((z1 == 'C') && (z2 == 'B')){
		cout << '1';
		return 0;
	} else {
		cout << '0';
		return 0;
	}
}
