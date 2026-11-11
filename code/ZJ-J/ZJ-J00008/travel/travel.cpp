#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int k1=(s1[0]-'0')*10+(s1[1]-'0'),k2=(s2[0]-'0')*10+(s2[1]-'0');
	if(c1==c2){
		cout<<1;
		cout<<(k1==k2);
		cout<<(k1==k2&&!((s1[2]>'C')^(s2[2]>'C')));
		cout<<(k1==k2&&!((s1[2]>'C')^(s2[2]>'C'))&&abs(s1[2]-s2[2])==1);
	}else{
		cout<<"0000";
		return 0;
	}
	return 0;
}
