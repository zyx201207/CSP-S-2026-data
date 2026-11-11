#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std ;

#define ll long long
#define MAX 2147483647
#define N 200000 + 13
#define endl '\n'

int c1, c2 ;
string s1, s2 ;
int main() {
	freopen("travel.in", "r", stdin) ;
	freopen("travel.out", "w", stdout) ;
	ios::sync_with_stdio(0) ;
	cin.tie(0) ; cout.tie(0) ;
	
	cin >> c1 >> s1 >> c2 >> s2 ;
	
	//车厢相等 
	if(c1 == c2) {
		cout << 1 ;
		//排数相等
		if(s1[0] == s2[0] && s1[1] == s2[1]) {
			cout << 1 ;
			
			//在过道同侧 
			char a = s1[2], b = s2[2] ;
			if(a <= 'C' && b <= 'C') {
				cout << 1 ;
				
				//相邻（必有中间的 
				if(a != 'B' && b != 'B') {
					cout << 0 ;
				}
				else {
					cout << 1 ;
				}
			} 
			else if(a >= 'D' && b >= 'D') {
				//同侧必相邻 
				cout << "11" ;
			}
			else {
				cout << "00" ;
			}
		}
		else {
			cout << "000" ;
		}
	} 
	else {
		cout << "0000" ;
	}
	return 0 ;
}

