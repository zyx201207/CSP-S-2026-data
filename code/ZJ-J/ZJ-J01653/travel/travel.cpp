#include <bits/stdc++.h>
#define ll long long
using namespace std;
string c1, s1, c2, s2;
ll a1, b1;
char a2, b2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1 == c2){
		cout<<"1";
		a1 = s1[0]-'0';
		a1 *= 10;
		a1 += s1[1] - '0';
		b1 = s2[0]-'0';
		b1*=10;
		b1+=s2[1] - '0';
		if(a1==b1){
			cout<<"1";
			
		a2 = s1[2];
		b2 = s2[2];
		if((a2 == 'A'||a2=='B'||a2=='C') &&(b2=='A'||b2=='B'||b2=='C')){
			cout<<"1";
			if(a2 == 'A' && b2 == 'B'){
				cout<<"1";
			}else if (a2 == 'B' && b2 == 'C'){
				cout<<"1";
			}else if (a2 == 'B' && b2 == 'A'){
				cout<<"1";
			}else if (a2 == 'C' && b2 == 'B'){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}else if ((a2 == 'D' || a2 == 'F') && (b2 == 'D' || b2 == 'F')){
			cout<<"11";
		}else{
			cout<<"00";
		}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	
	return 0;
}
