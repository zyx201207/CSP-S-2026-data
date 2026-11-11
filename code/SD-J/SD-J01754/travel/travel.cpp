#include<bits/stdc++.h>
using namespace std;
#define itn int
#define endl "\n"
#define ll long long
string s[15];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s[0]>>s[1]>>s[2]>>s[3];
	for(int i=0;i<=1;i++){
		if(s[0][i]!=s[2][i]){
			cout<<"0000";
			return 0;
		}
	}cout<<1;
	for(int i=0;i<=1;i++){
		if(s[1][i]!=s[3][i]){
			cout<<"000";
			return 0;
		}
	}cout<<1;
	if(('A'<=s[1][2]&&s[1][2]<='C'&&'A'<=s[3][2]&&s[3][2]<='C')||('D'<=s[1][2]&&s[1][2]<='E'&&'D'<=s[3][2]&&s[3][2]<='E'))cout<<1;
	else{
		cout<<"00";
		return 0;
	}if(s[1][2]+1==s[3][2]||s[1][2]==s[3][2]+1)cout<<1;
	else cout<<0;
	return 0;
}
