#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	//两张车票对应的座位是否在同一节车厢
	if(c1 == c2){
		cout << "1";
		//两张车票对应的座位是否在同一排
		if(s1[0] == s2[0] && s1[1] == s2[1]){
			cout << "1";
			//两张车票对应的座位是否位于过道的同一侧
			//A=65 C= 67 F=70
			if(s1[2] <= 67 && s2[2] <= 67){
				cout << "1";
			}else if(s1[2] > 67 && s2[2] > 67){
				cout << "1";
			}else{
				cout << "0";
			}
		}else{
			cout << "00";
		}
		
		//两张车票对应的座位是否相邻
		if(s1[0] == s2[0] && s1[1] == s2[1]){
			if(abs(s1[2] - s2[2]) == 1 && !(s1[2] == 'C' || s2[2] == 'C')){
				cout << "1";
			}else{
				cout << "0";
			}
		}else{
			if(s1[2] == s2[2]
			  && abs(10*(s1[0]-s2[0])+(s1[1]-s2[1])) == 1
			){
				cout << "1";
			}else{
				cout << "0";
			}
		}
	}else{
		cout << "0000";
		
	}
	//cout << endl << (int)'A' << " " << (int)'C';
	return 0;
}
