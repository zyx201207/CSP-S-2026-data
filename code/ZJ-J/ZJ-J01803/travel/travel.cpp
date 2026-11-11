#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c[2],d[2];
	string s,t;
	cin>>c[2]>>s>>d[2]>>t;
	if(c[2]==d[2]){
		if(s[1]>t[1]||s[1]<t[1])
			cout<<"1000";
		else{
			if(s[2]<='C'&&t[2]>='D'||s[2]>='D'&&t[2]<='C')
				cout<<"1100";
			else{
				if(s[2]-t[2]>1||t[2]-s[2]>1)
					cout<<"1110";
				else
					cout<<"1111";
			}
		}		
	}
	else
		cout<<"0000";
	return 0;
}
