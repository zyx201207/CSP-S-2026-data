#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int a = 0,b = 0,c = 0,d = 0;
	int s = 1;
	for(int i = 1;i >= 0;i --){
		a += (c1[i] - '0') * s;
		b += (s1[i] - '0') * s;
		c += (c2[i] - '0') * s;
		d += (s2[i] - '0') * s;
		s *= 10;
	}  
	if(a == c)cout << 1;
	else{
		cout << "0000";
		return 0;	
	} 
	if(b == d)cout << 1;
	else{
		cout << "000";
		return 0;
	} 
	if((s1[2] - 'A' <= 2 && s2[2] - 'A'<= 2) || (s1[2] >= 'D' && s2[2] >= 'D'))cout << 1;
	else{
		cout << "00";
		return 0;
	}
	if(abs(s1[2] - s2[2]) == 1)cout << 1;
	else cout << 0;
	return 0;
}
