#include<bits/stdc++.h>
using namespace std;
string s,s1,n,m;
int main()
{
	freopen("travel.in" ,"r",stdin);
	freopen("travel.out","w",stdout);
	cin >> s >>n;
	cin >> s1 >>m;
	
	if(s[0] == s1[0])	cout <<  1;
	else cout << 0;
	
	if(s[2] == s1[2])	cout <<  1;
	else cout << 0;
	
	if(n[1] == m[1])	cout <<  1;
	else cout << 0;	
	
	if(n[1] == m[1]){
		if(n[2]!=m[2]){
			if(n[2]+1 == m[2] || n[2]-1 == m[2])	cout <<  1;
			else cout << 0;		
		}
		else cout <<0;
	}
	else cout << 0;

	
	
	return 0;
}
