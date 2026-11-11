#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,c2,s1,s2;//c:车厢，s:座位   1：小R    2：小X 
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2) cout << 1;
	else {
		cout << 0 << 0 << 0 << 0;
		return 0;
	}
	string p1=s1.substr(0,2),p2=s2.substr(0,2),z1=s1.substr(2,2),z2=s2.substr(2,2);
	//cout << p1 << " " << p2 << endl;
	if(p1==p2) cout << 1;
	else {
		cout << 0 << 0 << 0;
		return 0;
	}
	if(z1>="D"&&z2>="D"||z1<="C"&&z2<="C") cout <<1;
	else {
		cout << 0 << 0;
		return 0;
	}
	if(z1=="C"&&z2=="A"||z1=="A"&&z2=="C") cout << 0;
	else cout << 1;
	return 0;
} 
