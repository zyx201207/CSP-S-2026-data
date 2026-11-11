//SN-J00797 霍彧昂 西安辅轮中学
#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin >> c1 >> s1 >> c2 >> s2;
	string a = s1.substr(0,2);
	string b = s2.substr(0,2);
	
	string x = s1.substr(2,1);
	string y = s2.substr(2,1);
	
	bool flag = true;
	
	if(c1 == c2) cout << 1;
	else{
		cout << 0;
		flag = 0;
	}
	if(a == b && flag == 1) cout << 1;
	else{
		cout << 0;
		flag = 0;
	}
	if((((x=="A" || x=="B" || x=="C") && (y=="A" || y=="B" || y=="C") && x != y) || ((x=="D" || x=="F") && (y=="D" || y=="F") && x != y)) && flag == 1) cout << 1;
	else{
		cout << 0;
		flag = 0;
	}
	if(((x=="A" && y=="B") || (x=="B" && (y=="A" || y=="C")) || (x=="C" && y=="B") || (x=="D" && y=="F") || (x=="F" && y=="D")) && flag == 1) cout << 1;
	else cout << 0;
	
	return 0;
}
