#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5;
string c[5],s[5]; 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c[1]>>s[1]>>c[2]>>s[2];
	if(c[1]==c[2]){
		cout<<1;
		if(s[1][0]==s[2][0]&&s[1][1]==s[2][1]){
			cout<<1;
			if((s[1][2]>='D'&&s[2][2]>='D')||(s[1][2]<'D'&&s[2][2]<='D')){
				cout<<1;
				if((char(s[1][2]+1)==s[2][2])||(char(s[1][2]-1)==s[2][2])){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0;
				cout<<0;
			}
		}else{
			cout<<0;
			cout<<0;
			cout<<0;
		}
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
	}
	return 0;
}
