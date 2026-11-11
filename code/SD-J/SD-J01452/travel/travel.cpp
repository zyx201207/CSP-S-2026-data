#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s1,s2,c1,c2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2) {
	    puts("0000");
	    return 0;
	}
	else cout<<'1';
	int a1=(s1[0]-'0')*10+s1[1]-'0';
	int a2=(s2[0]-'0')*10+s2[1]-'0';
	if(a1==a2) cout<<'1';
	else{
		puts("000");
		return 0;
	}
	if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')) cout<<'1';
	else {
		puts("00");
		return 0;
	}
	if(abs(s1[2]-s2[2])==1) cout<<'1'<<endl;
	else puts("0");
	return 0;
}
