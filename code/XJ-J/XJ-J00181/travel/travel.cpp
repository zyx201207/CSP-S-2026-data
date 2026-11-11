#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,t1,s2,t2;
	cin >> s1 >> t1 >> s2 >> t2;
	int c1,c2;
	if(s1[0] == '0'){
		c1 = s1[1] - '0';
	}else{
		c1 = s1[0]-'0';
		c1 = c1 *10;
		c1 += s1[1]-'0';
	}
	if(s2[0] == '0'){
		c2 = s2[1] - '0';
	}else{
		c2 = s2[0]-'0';
		c2 = c2 *10;
		c2 += s2[1]-'0';
	}
	if(c1 == c2){
		cout<<1;
		if(t1[0] == t2[0] && t1[1] == t2[1]){
			cout<<1;
			if(t1[2] >= 'D' && t2[2] >= 'D'){
				cout<<1<<1;
			}else if(t1[2] < 'D' && t2[2] < 'D'){
				cout<<1;
				if (t1[2] == 'A' && t2[2] == 'B'){
					cout<<1;
				}else if(t1[2] == 'B'){
					if(t2[2] == 'A' || t2[2] == 'C'){
						cout << 1;
					}
				}else if(t1[2] == 'C' && t2[2] == 'B'){
					cout<<1;
				}else{
					cout<<0;
				} 
			}else{
				cout<<0<<0;
			}
		}else{
			cout<<0<<0<<0;
		} 
	}else{
		cout<<0<<0<<0<<0;
	} 
	return 0;
}
