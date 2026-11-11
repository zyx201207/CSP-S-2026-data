#include <bits/stdc++.h>
using namespace std;

string a,ac,b,bc;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> a >> ac >> b >> bc;
	int a_1=0,b_1=0,a_2=0,b_2=0;
	if (a==b){
		a_1++;
	}
	//1
	if (ac[0]==bc[0] && a_1==1 && ac[1]==bc[1]){
		if (ac[1]==bc[1]) b_1++;
	}
	//2
	if (b_1==1 && ((ac[2]<='C'&&bc[2]<='C') || (ac[2]>='C'&&bc[2]>='C'))){
		a_2++;
	}
	//3
	if (a_2==1 && ((ac[2]=='A'&&bc[2]<='B') || (ac[2]=='B'&&bc[2]=='C') || (ac[2]=='D'&&bc[2]=='F'))) b_2++;
	//4
	cout << a_1 << b_1 << a_2 << b_2;
	return 0;
} 
