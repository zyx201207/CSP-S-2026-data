#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1,s1,c2,s2;
bool flag=true;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
		cout<<1;
	else{
		cout<<0;
		flag=false;
	}
	ll cs1=s1[0]*10+s1[1],cs2=s2[0]*10+s2[1];
	if(flag&&(cs1==cs2))
		cout<<1;
	else{
		cout<<0;
		flag=false;
	}
	bool q1=(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'),q2=(s2[2]=='A'||s2[2]=='B'||s2[2]=='C');
	if((q1==q2)&&flag)
		cout<<1;
	else{
		cout<<0;
		flag=false;
	}
	if(flag&&(!((s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A'))))
		cout<<1;
	else
		cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}