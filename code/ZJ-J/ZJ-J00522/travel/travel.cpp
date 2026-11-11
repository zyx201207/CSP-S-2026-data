#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
short a[256];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		cout << "1";
	}else{
		cout << "0000";
		return 0;
	}
	if(s1[0] == s2[0] && s1[1] == s2[1]){
		cout << "1";
	}else{
		cout << "000";
		return 0;
	}
	a[s1[2]]++,a[s2[2]]++;
	if((a['A']==1&&a['B']==1)||(a['A']==1&&a['C']==1)||(a['B']==1&&a['C']==1)||(a['D']==1&&a['F']==1)){
		cout << "1";
	}else{
		cout << "00";
		return 0;
	}
	if((a['A']==1&&a['B']==1)||(a['B']==1&&a['C']==1)||(a['D']==1&&a['F']==1)){
		cout << "1";
	}else{
		cout << "0";
	}
	return 0;
}
