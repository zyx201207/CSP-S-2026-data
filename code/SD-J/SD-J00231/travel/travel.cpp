#include <bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2) cout << 1;
	else{
		cout << "0000";
		return 0;
	} 
	string ss1 = "",ss2 = "";
	for(int i = 0;i < 2;i++) ss1 += s1[i];
	for(int i = 0;i < 2;i++) ss2 += s2[i];
	if(ss1 == ss2) cout << 1;
	else{
		cout << "000";
		return 0;
	}
	char in1 = s1[2],in2 = s2[2];
	bool flag;
	if(in1 == 'A' || in1 == 'B' || in1 == 'C'){
		flag = 0;
	} 
	if(flag == 0){
		if(in2 == 'A' || in2 == 'B' || in2 == 'C') cout << 1;
		else{
			cout << "00";
			return 0;
		} 
	}else{
		if(in2 == 'D' || in2 == 'F') cout << 1;
		else{
			cout << "00";
			return 0;
		}
	}
	if(flag == 1) cout << 1;
	else{
		if((char)in1 + 1 == (char)in2 || (char)in1 - 1 == (char)in2) cout << 1;
		else cout << 0;
	}
	return 0;
}

