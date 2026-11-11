#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0); 
	string c1,s1,c2,s2;
	set<char> s,t;
	s.insert('A');
	s.insert('B');
	s.insert('C');
	t.insert('D');
	t.insert('E');
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0] and s1[1]==s2[1]){
			cout<<1;
			if(s.count(s1[2]) and s.count(s2[2]) or t.count(s1[2]) and t.count(s2[2])){
				cout<<1;
				if(abs(s1[2]-s2[2])==1){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
