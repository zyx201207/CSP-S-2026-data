#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >>s1 >> c2 >> s2;
	if(c1 != c2){
		cout<<"0000";
		
		return 0;
	}
	int b = s1[2]-'A',c=s2[2]-'A';
	if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		cout << "1000";
		return 0;
	}if((b<=2&&c>=3)||(b>=3&&c<=2)){
		cout << "1100";
		return 0;
	}if(b!=c+1&&b!=c-1){
		if((b==3&&c==5)||(b==5&&c==3)){
			cout << "1111";
			return 0;
		}
		cout << "1110";
		return 0;
	}
	cout << "1111";
	return 0;
}
