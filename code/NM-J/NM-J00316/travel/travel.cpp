#include<bits/stdc++.h>
using namespace std;
char c1[3], c2[4], s1[3], s2[4];
int a[2], b[2], c[2], d[2];
bool bo;
char ch, ca;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	for(int i = 0; i < 2; i ++){
        cin >> c1[i];
        a[i] = c1[i] - '0';
	}
	scanf(" "); 
	for(int i = 0; i < 3; i ++){
        cin >> c2[i];
	}
	scanf(" "); 
	for(int i = 0; i < 2; i ++){
        cin >> s1[i];
        b[i] = s1[i] - '0';
	}
	scanf(" "); 
	for(int i = 0; i < 3; i ++){
        cin >> s2[i];
	}
	for(int i = 0; i < 2; i ++){
		if(a[i] != b[i]){
			cout << 0 << 0 << 0 << 0;
			return 0;
		}
	}
	cout << 1;
	for(int i = 0; i < 2; i ++){
        c[i] = c2[i] - '0';
        d[i] = s2[i] - '0';
	}
	for(int i = 0; i < 2; i ++){
		if(c[i] != d[i]){
			cout << 0 << 0 << 0;
			return 0;
		}
	}
	cout << 1;
	if((c2[2] == 'A'&&s2[2] == 'B') || (c2[2] == 'A'&&s2[2] == 'C') || (c2[2] == 'B'&&s2[2] == 'C') || (c2[2] == 'B'&&s2[2] == 'A') || (c2[2] == 'C'&&s2[2] == 'B')||(c2[2] == 'C'&&s2[2] == 'A') || (c2[2] == 'B'&&s2[2] == 'A') || (c2[2] == 'C'&&s2[2] == 'B') || (c2[2] == 'D'&&s2[2] == 'F') || (c2[2] == 'F'&&s2[2] == 'D')){
		cout << 1;
	}
	else {
		cout << 0 << 0;
		return 0;
	}
	if((c2[2] == 'A'&&s2[2] == 'B') || (c2[2] == 'B'&&s2[2] == 'C') || (c2[2] == 'A'&&s2[2] == 'B')||(c2[2] == 'B'&&s2[2] == 'A') || (c2[2] == 'C'&&s2[2] == 'B') || (c2[2] == 'D'&&s2[2] == 'F') || (c2[2] == 'F'&&s2[2] == 'D')){
		cout << 1;
	}
	else {
		cout << 0;
	}
	return 0;

}


