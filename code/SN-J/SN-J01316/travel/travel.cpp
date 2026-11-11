#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if (c1 == c2){
		cout<<'1';
		if (10 * (int(s1[0])) + int(s1[1]) == 10 * (int(s2[0])) + int(s2[1])){
			cout<<'1';
			if ((s1[2] <= 'C' && s2[2] <= 'C') or (s1[2] > 'C' && s2[2] > 'C')){
				cout<<'1';
				if (s1[2] + 1 == s2[2] or s1[2] - 1 == s2[2]){
					cout<<'1';
				}
				else cout<<'0';
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
