#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		int a=(s1[0]-48)*10+s1[1]-48;
		int b=(s2[0]-48)*10+s2[1]-48;
		if(a==b){
			cout<<"1";
			if((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='E'&&s2[2]>='D'&&s2[2]<='E')){
				cout<<"1";
				int x=s1[2];
				int y=s2[2];
				if(abs(x-y)==1) cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
		
	}
	else cout<<"0000";
	return 0;
}
