#include <iostream>
#include <string>
using namespace std;
int main{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1, s1, c2, s2;
	cin >> c1;
	cin >> s1;
	cin >> c2;
	cin >> s2;
	if(c1[0]==s1[0]&&c1[1]==s[1]){
		cout << 1;
		if(c2[0]==s2[0]){
			cout << 1;
			if(c2[1]==s2[1]){
				cout << 1;
				if(c2[2]+1==s2[2]||s2[2]+1==c2[2]){
					cout << 1;
				}
				else{
					cout << 0;
				}
			}
			else{
				cout << 0;
			}
		}
		else{
			cout << 0;
		}
	}
	else{
		cout << 0;
	}
	fclose(stdin); 
	fclose(stdout); 
	return 0;
}
