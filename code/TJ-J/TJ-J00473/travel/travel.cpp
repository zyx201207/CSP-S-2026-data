#include <bits/stdc++.h>
#define ll long long
#define pll pair<long long,long long>
using namespace std; 

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin >> s1 >> s2 >> s3 >> s4;
	if(s1 == s3){
		cout << 1;
	}else{
		cout << 0;
	}if(s1 == s3 and s2[0] == s4[0] and s2[1] == s4[1]){
		cout << 1;
	}else{
		cout << 0;
	}int f1,f2;
	f1 = (s2[2] >= 'D' and s2[2] <= 'F');
	f2 = (s4[2] >= 'D' and s4[2] <= 'F');
	cout << (f1 == f2 and s1 == s3 and s2[0] == s4[0] and s2[1] == s4[1]);
	if(s1 == s3 and s2[0] == s4[0] and s2[1] == s4[1] and (s2[2]+1 == s4[2] or s2[2]-1 == s4[2]) and f1 == f2){
		cout << 1;
	}else{
		cout << 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
