#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string C, c, S, s;
	cin >> C >> S >> c >> s;
	if(C==c){
		if(S[0] == s[0] && S[1] == s[1]){
			if((S[2] == 'F' && s[2] == 'D') || (s[2] == 'D' && S[2] == 'F') || (s[2] == 'A' && S[2] == 'B')||(S[2] == 'A' && s[2] == 'B')||(s[2] == 'A' && S[2] == 'C')||(S[2] == 'A' && s[2] == 'C')||(s[2] == 'B' && S[2] == 'C')||(S[2] == 'B' && s[2] == 'C')){
				if(S[2]-'0'+1 == s[2]-'0' || S[2]-'0'-1 == s[2]-'0'){
					cout << "1111";
				}
				else
					cout << "1110";
			}	
			else
				cout << "1100";
		}
		else
			cout << "1000";
	}
	else
		cout << "0000";
	return 0;
}
