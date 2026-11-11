#include <bits/stdc++.h>
using namespace std;
#define int long long
string c1,s1,c2,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2){//同车厢 
		if (s1[0]==s2[0]&&s1[1]==s2[1]){//同排 
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]>='D'))//同侧 
			{
				if (abs((s1[2]-'A')-(s2[2]-'A'))==1){
					cout << "1111\n";
					return 0;
				}else{
					cout << "1110\n";
					return 0;
				}
			}else{
				cout << "1100\n";
				return 0;
			}
		}else{
			cout << "1000\n";
			return 0;
		}
	}else{
		cout << "0000\n"; 
		return 0;
	}
	return 0;
}
