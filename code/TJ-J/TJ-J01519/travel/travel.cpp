#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
typedef long long ll;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool a=0,b=0,c=0,d=0;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	} else{
		a=1;
	}
	if(s1[1]==s2[1]){
		b=1;
	}
	if(b&&s1[2]<='C'&&s1[2]>='A'&&s2[2]<='C'&&s2[2]>='A'){
		c=1;
	}else if(b&&s1[2]>='D'&&s1[2]<='E'&&s2[2]>='D'&&s2[2]<='E'){
		c=1;
	}
	if(s2[2]-s1[2]==1&&s2[2]!='D'&&s1[2]!='C'){
		d=1;
	}
	cout<<a<<b<<c<<d;
	return 0;
}
