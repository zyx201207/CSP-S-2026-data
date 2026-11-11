#include<bits/stdc++.h>
using namespace std;
#define int long long
int c1,c2;
string s1,s2;
int a[10];
int a1,a2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c1 >> s1 >> c2 >>s2;
	if (c1 == c2){
		a[1] = s1[0]-'0';
		a[2] = s1[1]-'0';
		a[3] = s2[0]-'0';
		a[4] = s2[1]-'0';
		a1 = 10*a[1]+a[2];
		a2 = 10*a[3]+a[4];
		if (a1 == a2){
			if (s1[2]-'0'>= 17&&s1[2]-'0'<= 19){
				if (s2[2]-'0'>= 17&&s2[2]-'0'<= 19){
					if (s1[2]-'0' == 18||s2[2]-'0' == 18)cout << "1111";
					else cout << "1110";
				}
				else cout << "1100";
				
			}
			//cout << s1[2]-'0';
			if (s1[2]-'0'>= 20&&s1[2]-'0'<= 21){
				if (s2[2]-'0'>= 20&&s2[2]-'0'<= 21){
					cout << "1111";
				}
				else cout << "1100";
				
			}
			//cout << s2[2]-'0';
		}
		else cout << "1000";
		
	}
	else cout << "0000";

	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
