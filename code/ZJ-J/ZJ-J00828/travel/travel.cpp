#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1, c2;
	string s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int num1 = (s1[0]-'0')*10+(s1[1]-'0');
	int num2 = (s2[0]-'0')*10+(s2[1]-'0');
	int sum1 = (s1[2]-'A');
	int sum2 = (s2[2]-'A');
	cout << (c1 == c2);
	cout << (c1 == c2 && num1 == num2);
	cout << (c1 == c2 && num1 == num2 && sum1/3 == sum2/3);
	cout << (c1 == c2 && num1 == num2 && sum1/3 == sum2/3 && abs(sum1-sum2) == 1);
	return 0;
}
