#include <bits/stdc++.h>
#define int long long
using namespace std;
int chexiang_a = 0,pai_a = 0,chexiang_b = 0,pai_b = 0; 
int seat_a = 0,seat_b = 0;
string s;
bool p(int a,int b){
	if((a < 4 && b < 4) || (a > 4 && b > 4)){
		return 1;
	}
	return 0;
}
signed main(){
	   freopen("travel.in","r",stdin);
	   freopen("travel.out","w",stdout);
	   ios::sync_with_stdio(false);
	   cin.tie(0);
	   cout.tie(0);
	   cin >> chexiang_a;
	   cin >> s;
	   int len = s.size();
	   for(int i = 0;i < len;i ++){
	   		if(i < 2){
	   			pai_a = pai_a * 10 + (s[i] - '0');	
			}
			else{
				seat_a = s[i] - 'A' + 1;
				if(seat_a == 4){
					seat_a = 5;
				}
			}
	   }
	   cin >> chexiang_b;
	   cin >> s;
	   len = s.size();
	   for(int i = 0;i < len;i ++){
	   		if(i < 2){
	   			pai_b = pai_b * 10 + (s[i] - '0');	
			}
			else{
				seat_b = s[i] - 'A' + 1;
				if(seat_b == 4){
					seat_b = 5;
				}
			}
	   }
	   //cout << chexiang_a << ' ' << pai_a << ' ' << seat_a << '\n';
	   //cout << chexiang_b << ' ' << pai_b << ' ' << seat_b;
	   if(chexiang_a == chexiang_b){
			cout << 1;
			if(pai_a == pai_b){
				cout << 1;
				if(p(seat_a,seat_b)){
					cout << 1;
					if(abs(seat_a - seat_b) == 1){
						cout << 1;
					}
					else{
						cout << 0;
					}
				}
				else{
					cout << "00";
				}
			}
			else{
				cout << "000";
			}
	   } 
	   else{
			cout << "0000";
	   }
	   return 0;
 }

