#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	
	int c1,c2;
	string s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1!=c2){cout << "0000";return 0;}
	if(s1[0]!=s2[0] || s1[1]!=s2[1]){cout << "1000";return 0;}
	if(s1[2]<'D'&&s2[2]>'C' || s1[2]>'C'&&s2[2]<'D'){cout << "1100";return 0;}
	if(s1[2]=='A'&&s2[2]=='C' || s1[2]=='C'&&s2[2]=='A'){cout<< "1110";return 0;}
	cout <<"1111";
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
