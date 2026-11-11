#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	map<char, int> mp;
	mp['A'] = mp['B'] = mp['C'] = 1;
	mp['D'] = mp['F'] = 2;
	string s1;
	string s2;
	string s3;
	string s4;
	cin >> s1 >> s2 >> s3 >> s4;
	
	if(s1 == s3){
		cout << 1;
	}//1st
	else{
		cout << 0;
	}
	
	if(s1 == s3 
	&&
	s2[0] == s4[0]
	&&
	s2[1] == s4[1]){
		cout << 1;
	}//2nd
	else{
		cout << 0;
	}
	
	if(s1 == s3 
	&&
	s2[0] == s4[0] 
	&& 
	s2[1] == s4[1]
	&&
	mp[s2[2]] == mp[s4[2]]
	){
		cout << 1;
	}//3rd
	else{
		cout << 0;
	}
	
	if(s1 == s3 
	&&
	s2[0] == s4[0] 
	&& 
	s2[1] == s4[1]
	&&
	mp[s2[2]] == mp[s4[2]]
	&&
	abs(s2[2] - s4[2]) == mp[s2[2]]){
		cout << 1;
	}
	else{
		cout << 0;
	}
	return 0;
}