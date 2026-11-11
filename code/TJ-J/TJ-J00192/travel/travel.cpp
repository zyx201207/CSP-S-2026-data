#include<iostream>
#include<cstdio>
using namespace std;
int c1;
string s1;
int c2;
string s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >>s1 >>c2 >> s2;
	if(c1 == c2)
	{
		cout << "1";
	}
	else
	{
		cout << "0";
	}
	if(c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1])
	{
		cout << "1";
		if((s1[2] - 0 == 65 || s1[2] - 0 == 66 || s1[2] - 0 == 67) && (s2[2] - 0 == 65 || s2[2] - 0 == 66 || s2[2] - 0 == 67))
			cout << "1";
		else if ((s1[2] - 0 == 68 || s1[2] - 0 == 70) && (s2[2] - 0 == 68 || s2[2] - 0 == 70))
			cout << "1";
		else
			cout << "00";
			return 0;
		if((s1[2] - 0 ) - (s2[2] - 0) == 1 || (s2[2] - 0) - (s1[2] - 0) == 1)
			cout << "1";
    	else
		{
    		if((s1[2] - 0 == 68 && s2[2] - 0 == 70) || (s1[2] - 0 == 70 && s2[2] - 0 == 68))
    			cout << "1";
    		else	
				cout << "0";
		}
	}
	else
		cout<< "000";
	return 0;
}
