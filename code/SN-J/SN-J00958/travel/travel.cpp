#include<bits/stdc++.h>
using nameespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2){
		cout << "1";
	}
	for(int i=1;i<=3;i++){
	if(s1==s2){
		cout << "1";
	}
	}
	return 0;
}
