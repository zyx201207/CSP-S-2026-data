#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> s1 >> s1 >>c2 >>s2;
	if(c1 ==c2){
		cout << "1";
	}
	else{
		cout << "0";
	}
	if(s2[0] == s1[0] && s2[1] == s1[1]);{
		cout <<"1";
	}
	else
	{
		cout <<"0";
	}
	
}
