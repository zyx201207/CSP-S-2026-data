#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0); 
	cin.tie(0);cout.tie(0);
	string s,ss,str,strr;
	cin >> s >> str >> ss >> strr;
	if(s == ss){
		cout << '1';
	}
	else{
		cout << "0000";
		return 0;
	}
	if(str[0] == strr[0] && str[1] == strr[1]){
		cout << '1';
		if(str[2] == 'A' || str[2] == 'B' || str[2] == 'C'){
			if(strr[2] == 'A' || strr[2] == 'B' || strr[2] == 'C'){
				cout << '1';
				if(str[2] == 'A'){
					if(strr[2] == 'B')
					{
						cout << '1';
						return 0;
					}
					else{
						cout << '0';
						return 0;
					}
				}
				else if(str[2] == 'B'){
					if(strr[2] == 'A' || strr[2] == 'C')
					{
						cout << '1';
						return 0;
					}
					else{
						cout << '0';
						return 0;
					}
				}
				else if(str[2] == 'C'){
					if(strr[2] == 'B')
					{
						cout << '1';
						return 0;
					}
					else{
						cout << '0';
						return 0;
					}
				}
			}
		}
		if(str[2] == 'D' || str[2] == 'F'){
			if(strr[2] == 'D' || strr[2] == 'F'){
				cout << '1';
				if(str[2] == 'D'){
					if(strr[2] == 'F')
					{
						cout << '1';
						return 0;
					}
					else{
						cout << '0';
						return 0;
					}
				}
				if(str[2] == 'F'){
					if(strr[2] == 'D')
					{
						cout << '1';
						return 0;
					}
					else{
						cout << '0';
						return 0;
					}
				}
			}
		}
	}
	else{
		cout << "000";
	}
	
	return 0; 
} 
