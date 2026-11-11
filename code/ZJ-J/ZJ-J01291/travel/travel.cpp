#include<bits/stdc++.h>
using namespace std;

int n, m;
string s1, s2;

int sit(char s){
	return (s == 'F' ? 4 : (s - 'A'));
}

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>s1>>m>>s2;
	if(n != m)cout<<"0000";
	else{
		cout<<1;
		int ln1 = (s1[0]-'0')*10+(s1[1]-'0');
		int ln2 = (s2[0]-'0')*10+(s2[1]-'0');
		if(ln1 != ln2)cout<<"000";
		else{
			cout<<1;
			int st1 = sit(s1[2]);
			int st2 = sit(s2[2]);
			if(!(st1 <= 2 && st2 <= 2) && !(st1 >= 3 && st2 >= 3))cout<<"00";
			else{
				cout<<1;
				if(abs(st1-st2) == 1)cout<<1;
				else cout<<0;
			}
		}
	}
	return 0;
} 
