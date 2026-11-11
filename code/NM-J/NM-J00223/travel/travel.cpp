#include <bits/stdc++.h> 
using namespace std;

string c1,s1,c2,s2;
int ans1,ans2,ans3;
int pos1,pos2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s="ABCDF" ;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2){
		cout << 1;
		ans1++;
	}
	else{
		cout << 0;
	}
	if(s1[0]==s2[0] && s1[1]==s2[1] && ans1){
		cout << 1;
		ans2++;
	}
	else cout << 0;
	for(int i=0;i<5;i++){
		if(s[i]==s1[2]) pos1=i;
		if(s[i]==s2[2]) pos2=i;
	}
	if(((pos1 <= 2 && pos2 <= 2) || (pos1 > 2 && pos2 > 2)) && ans2){
		cout << 1;
		ans3++;
	}
	else cout << 0;
	if(abs(pos1-pos2)==1 && ans3){
		cout << 1;
	}
	else cout << 0;
	return 0;
}