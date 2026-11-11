#include<bits/stdc++.h>
using namespace std;
int cnt,s2,a=0,b,c;
string s,s1;
int main(){
	cin >> b;
	for(int i=0;i<b;i++){
		cin >> c >> s1;
		for(int j=0;j<c;j++){
			s += s1;
		}
	}
	s2 = s.length()-1;
	s1 = s;
	while(true){
		if(a==s2-a){
			break;
		}
		if(s1[a]!=s1[s2-a]){
			s1[a] = s1[s2-a];
			cnt++;
		}
		a++;
	}
	cout << cnt;
}
