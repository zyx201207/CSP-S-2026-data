#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int len=s1.size();
	int tg=0;
	if (c1==c2){
		cout << "1";
	}
	else{
		cout << "0";
		tg=1;
	}
	int fg=0;
	if (tg==0){
		for (int i=0;i<s1.size()-1;i++){
			if (s1[i]!=s2[i]){
				fg=1;
				break;
			}
		}
		if (fg==0){
			cout << "1";
		}
		else{
			cout << "0";
		}
	}
	else{
		cout << "0";
		fg=1;
	}
	int op=0;
	if (fg==0){
		if ((s1[len-1]<='C' && s2[len-1]>'C') || (s2[len-1]<='C' && s1[len-1]>'C')){
			cout << "0";
			op=1; 
		}
		else{
			cout << "1";
		}
	}
	else{
		cout << "0";
		op=1;
	}
	if (op==0){
		if (s1[len-1]+1==s2[len-1] || s2[len-1]+1==s1[len-1]){
			cout << "1";
		}
		else{
			cout << "0";
		}
	}
	else{
		cout << "0";
	}
	return 0;
}
