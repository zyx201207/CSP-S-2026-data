#include<bits/stdc++.h>
using namespace std;
int n, l = 1;
string s;
string c1, s1, c2, s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	getline(cin, s);
	for(int i = 0; i < s.size(); i++){
		if(s[i] == ' '){
			l++;
			continue;
		}
		if(l == 1){
			c1 += s[i];
		}
		else if(l == 2){
			s1 += s[i];
		}
		else if(l == 3){
			c2 += s[i];
		}
		else s2 += s[i];
	}
	if(c1 == c2) {
		cout<<"1";
		if(s1[0] == s2[0] && s1[1] == s2[1]){
			cout<<"1";
			if((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] > 'C' && s2[2] > 'C')){
				cout<<"1";
				if(abs(s1[2] - s2[2]) == 1){
					cout<<"1";
				}
				else cout<<"0";
			}
			else cout<<"00";
		} 
		else cout<<"000";
	} 
	else cout<<"0000";
	
	return 0;
}

