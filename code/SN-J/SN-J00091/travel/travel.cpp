#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,s1,c2,s2;
	string c_1,s_1,c_2,s_2;
	cin >> c_1 >> s_1 >> c_2 >> s_2;
	c1=int(c_1[0]-'0')*10+int(c_1[1]-'0');
	c2=int(c_2[0]-'0')*10+int(c_2[1]-'0');
	s1=int(s_1[0]-'0')*10+int(s_1[1]-'0');
	s2=int(s_2[0]-'0')*10+int(s_2[1]-'0');
	if(c1==c2){
		if(s1==s2){
			if((s_1[2]<=67&&s_2[2]<=67)||(s_1[2]>67&&s_2[2]>67)){
				if(abs(s_1[2]-s_2[2])==1){
					cout << 1;
				}
				else{
					cout << 1110;
					return 0;
				}
				cout << 1;
			}
			else{
				cout << 1100;
				return 0;
			}
			cout << 1;
		}
		else{
			cout << 1000;
			return 0;
	 	}
	 	cout << 1;
	}
	else{
		cout << "0000";
		return 0;
	}
}
