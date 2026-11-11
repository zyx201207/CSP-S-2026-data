#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
	int c1, c11 ,c2, c22;
	char s1, s2;
	cin >> c1 >> c11;
	cin >> s1;
	cin >> c2 >> c22;
	cin >> s2;
//	printf("%d %d%c %d %d%c\n",c1,c11,s1,c2,c22,s2);
	if(c1 == c2){
		cout << "1";
		if(c11 == c22){
			cout << "1";
			if((s1 >= 'A' && s1 <= 'C' && s2 >= 'A' && s2 <= 'C' && s1 != s2)||(s1 == 'D' && s2 == 'F') || (s1 == 'F' && s2 == 'D')){
				cout << "1";
				if(s1 != 'D' && s1 != 'F' && abs((int)s1-s2) == 1){
					cout << "1";
				}else if(s1 == 'D' || s2 == 'D'){
					cout << "1";
				}else{
					cout << "0";
				}
			}else{
				cout << "00";
			}
		}else{
			cout << "000";
		}
	}else{
		cout << "0000";
	}
	return 0;
} 
//Trick||Treat!
