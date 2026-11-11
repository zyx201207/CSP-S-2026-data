//许喆涵 SN-J00784 西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
int c1, c2;
string s1, s2, ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2)
		ans+='1';
	else{
		cout << "0000";
		return 0;
	}
	int a=(s1[0]-'0')*10+s1[1]-'0';
	int b=(s2[0]-'0')*10+s2[1]-'0';
	if(a==b)
		ans+='1';
	else{
		ans+="000";
		cout << ans;
		return 0;
	}
	char a1=s1[2];
	char b1=s2[2];
	if((a1=='A'||a1=='B'||a1=='C')&&(b1=='A'||b1=='B'||b1=='C')){
		ans+='1';
	}else if((a1=='D'||a1=='F')&&(b1=='D'||b1=='F')){
		ans+='1';
	}else{
		ans+="00";
		cout << ans;
		return 0;
	}
	if((a1=='A'&&b1=='B')||(a1=='B'&&b1=='C')||(a1=='B'&&b1=='A')||(a1=='C'&&b1=='B')||(a1=='D'&&b1=='F')||(a1=='F'&&b1=='D'))
		ans+='1';
	else
		ans+='0';
	cout << ans;
	return 0;
}
