#include<bits/stdc++.h>
using namespace std;
#define int long long
string s1,c1,s2,c2; 
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s1>>c1>>s2>>c2;
	if(!(s1[0]==s2[0]&&s1[1]==s2[1])){
		cout<<"0000";
	}
	else if(!(c1[0]==c2[0]&&c1[1]==c2[1])){
		cout<<"1000";
	}
	else if(!((c1[2]<='C'&&c2[2]<='C')||(c1[2]>'C'&&c2[2]>'C'))){
		cout<<"1100";
	}
	else if(!((c1[2]+1==c2[2])||(c1[2]-1==c2[2]))){
		cout<<"1110";
	} 
	else{
		cout<<"1111";
	}
	cout<<'\n';
	return 0;
}

