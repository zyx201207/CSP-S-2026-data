#include<iostream>
using namespace std;
int main()
{
	freopen("travel.in",'r',stdin);
	freopen("travel.out",'w',stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c2 != c1) cout << "0000";
	else{
		if(s1[0] != s2[0] || s1[1] != s2[1]) cout << "1000";
		else{
			if(s1[2]<='C'&&s2[2]>='D') cout << "1100";
			else if(s2[2]<='C'&&s1[2]>='D') cout << "1100";
			else{
				if(s1[2]<='C'&&s1[2]+1==s2[2]) cout << "1111";
				else if(s1[2]<='C'&&s1[2]-1==s2[2]) cout << "1111";
				else if(s1[2]=='D'&&s2[2]=='F') cout << "1111";
				else if(s1[2]=='F'&&s2[2]=='D') cout << "1111";
				else cout << "1110";
			}
		}
	}
	return 0;
}
