#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	string c1,s1,c2,s2;
	string s = "ABCDF";
	cin >> c1 >> s1 >> c2 >> s2;

	if (c1[1] == c2[1]){//判断同一车厢
		cout << 1;
		if (s1[1] == s2[1]){//判断同一排
		cout << 1;
		if((s1[2] == s[0])||(s1[2] == s[1])||(s1[2] == s[2])){
			if((s1[2] == s[0])||(s1[2] == s[1])||(s1[2] == s[2])){
				cout << 1;//同侧
						if(s1[2] == s[0]){//s1 = A s2 = B 判断相邻
		if (s2[2] == s[1]){
			cout << 1;
		}
		else{
			cout << 0;
		}
	}
		if(s1[2] == s[1]){//s1 = b s2=a || c
			if ((s2[2] == s[1])||(s2[2]==s[2])){
				cout << 1;
			}
			else{
				cout << 0;
			}

			}
		if(s1[2] == s[2]){//s1 = b s2=a || c
			if (s2[2] == s[1]){
				cout << 1;
			}
			else{
				cout << 0;
			}

		}
			}
			else{
				cout << 0;
				}
		}
			if((s1[2] == s[3])||(s1[2] == s[4])){//判断同侧
				if((s2[2] == s[3])||(s2[2] == s[4])){
					cout << 1;
							if(s1[2] == s[0]){//s1 = A s2 = B 判断相邻
		if (s2[2] == s[1]){
			cout << 1;
		}
		else{
			cout << 0;
			cout << 0;
		}
	}
		if(s1[2] == s[1]){//s1 = b s2=a || c
			if ((s2[2] == s[1])||(s2[2]==s[2])){
				cout << 1;
			}
			else{
				cout << 0;
			}

			}
		if(s1[2] == s[2]){//s1 = b s2=a || c
			if (s2[2] == s[1]){
				cout << 1;
			}
			else{
				cout << 0;
				cout << 0;
			}

		}
					}
				else{
					cout << 0;
					cout << 0;
					}

				}

		}
		else{
			cout << 0;
			cout << 0;
			cout << 0;
		}

		}
	else{
		cout << 0;
		cout << 0;
		cout << 0;
		cout << 0;
	}



	return 0;
}
