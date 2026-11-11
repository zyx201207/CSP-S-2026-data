#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1!=c2){
		cout << "0000";
		return 0;
	}else{
		string t1=s1.substr(0,2);
		string t2=s2.substr(0,2);
		if(t1!=t2){
			cout << "1000";
		}else{
			char ch1=s1[2];
			char ch2=s2[2];
			if(ch1<='C'&&ch2<='C'){
				if(abs(ch1-ch2)==1){
					cout << "1111";
				}else{
					cout << "1110";
				}
			}else if(ch1>='D'&&ch2>='D'){
				cout << "1111";
			}else{
				cout << "1100";
			}
		}
	}
	return 0;
}
