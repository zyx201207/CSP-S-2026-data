#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
string s1,s2,s3,s4,s5,s6;
char c1,c3;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	
	cin >> s1 >> s2 >> s3 >> s4;
	if(s1==s3){
		cout << 1;
	}else{
		cout << "0000" << endl;
		return 0;
	}
	s5+=s2[0];
	s5+=s2[1];
	s6+=s4[0];
	s6+=s4[1];
	if(s5==s6){
		cout << 1;
	}else{
		cout << "000" << endl;
		return 0;
	}
	c1 = s2[2];
	c3 = s4[2];
	if(c1=='A'||c1=='B'||c1=='C'){
		if(c3=='A'||c3=='B'||c3=='C'){
			cout << 1;
		}else{
			cout << "00" << endl;
			return 0;
		}
	}else{
		if(c3=='A'||c3=='B'||c3=='C'){
			cout << "00" << endl;
			return 0;
		}else{
			cout << 1;
		}
	}
	int t = c1,t2 = c3;
	if(abs(t-t2)==1||(c1=='D'&&c3=='F')){
		cout << 1 << endl;
	}else{
		cout << 0 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*
Trick||Treat!
17 18D 17 17F
*/
