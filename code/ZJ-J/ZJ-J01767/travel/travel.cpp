#include<bits/stdc++.h>
using namespace std;
#define For(i ,x ,y) for(int i = x; i <= y; ++ i)
#define Down(i ,x ,y) for(int i = x; i >= y; -- i)
#define int long long
string car1 ,car2 ,seat1 ,seat2 ,s1 ,s2;
char t1 ,t2;
signed main(){
	freopen("travel.in" ,"r" ,stdin);
	freopen("travel.out" ,"w" ,stdout);
	cin >> car1 >> seat1;
	cin >> car2 >> seat2;
	if(car1 == car2){
		cout << "1";
		For(i ,0 ,1) {
			s1 += seat1[i];
			s2 += seat2[i];
		}
		if(s1 == s2){
			cout << "1";
			t1 = seat1[2];
			t2 = seat2[2];
			if((t1 <= 'C' && t2 <= 'C' && t1 >= 'A' && t2 >= 'A') || (t1 >= 'D' && t2 >= 'D' && t1 <= 'E' && t2 <= 'E')){
				cout << "1";
				if(t1 + 1 == t2 || t1 - 1 == t2) cout << "1";
				else cout << "0";
			}else cout << "00";
		}else {
			cout << "000";
		}
	}else {
		cout << "0000";
	}
	return 0;
}