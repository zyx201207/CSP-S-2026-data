#include <bits/stdc++.h>
using namespace std;
char a[] = {'A', 'B', 'C'};
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s, s1, s2, s3, s4;
	bool e = 0;
	cin >> s >> s1 >> s2 >> s3;
	if(s == s2){
		s4 += '1';
	} 
	else s4 += '0';
	int jjs = 0, wjw = 0;
	for(int i = 0; i < s1.size() - 1; i++){
		jjs = jjs * 10 + s1[i] - '0';
	}
	for(int i = 0; i < s3.size() - 1; i++){
		wjw = wjw * 10 + s3[i] - '0';
	}
	if(jjs == wjw)
	e = 1;
	if(jjs == wjw && s4[0] == '1')
	s4 += '1';
	else s4 += '0';
	char st = 'F', st1 = 'F';
	bool x = 0, y = 0;
	for(int i = 0; i < 3; i++){
		if(s1[2] == a[i]){
			st = a[i];
			x = 1;
		} 
		if(s3[2] == a[i]){
			st1 = a[i];
			y = 1;
		} 
	}
	if(x == y && s4[0] == '1' && s4[1] == '1')
	s4 += '1';
	else s4 += '0';
	if(st == 'F' && st1 == 'F')
	s4 += '1';
	else if(abs(st - st1) == 1 && e == 1){
		s4 += '1';
	}
	else s4 += '0';
	cout << s4 << endl;
	return 0; 
}
