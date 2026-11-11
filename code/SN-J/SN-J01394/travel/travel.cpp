#include <bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;

int mj()
{
	if(s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C'){
		if(s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C'){
			return 1;
		}
	}	
	else if(s1[2] == 'D' || s1[2] == 'F'){
		if(s2[2] == 'D' || s2[2] == 'F'){
			return 1;
		}
	}
	return 0;
}
int sixseven()
{
	if(s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C'){
		if(s1[2] == s2[2] + 1 || s1[2] == s2[2] - 1){
			return 1;
		}
	}
	else if(s1[2] == 'D' || s1[2] == 'F'){
		if(s1[2] == s2[2] + 2 || s1[2] == s2[2] - 2){
			return 1;
		}
	}
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin); 
	freopen("travel.out","w",stdout);
	
	cin >> c1 >> s1 >> c2 >> s2;
	
	if(c1 == c2){
		cout << 1;
	} 
	else{
		cout << 0;
	}
	if(c2[1] == c2[1]){
		cout << 1;
		if(mj() == 1){
			cout << 1;
			cout << sixseven();
		}
		else{
			cout << 0;
		}
	}
	else{
		cout << 0;
	}
	
		
}
