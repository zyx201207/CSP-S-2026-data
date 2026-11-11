#include<bits/stdc++.h>
using namespace std;
//#define int long long
string s1,c1,s2,c2;
bool check(string S){
	if(S[2]=='A'||S[2]=='B'||S[2]=='C'){
		return 0;
	}else{
		return 1;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if(check(s1)==check(s2)){
				cout<<1;
				if(s1[2]-s2[2]==1||s1[2]-s2[2]==-1||(s1[2]=='D'&&s2[2]=='F')||(s2[2]=='D'&&s1[2]=='F')){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
				return 0;
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	return 0;
}