#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=1e5+5;
ll a[N];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(s1[1]==s2[1]&&s1[0]==s2[0]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(s1[2]=='F'){
		if(s2[2]=='D'){
			cout<<1;
			return 0;
		}
	}else if(s1[2]=='A'){
		if(s2[2]=='B'){
			cout<<1;
			return 0;
		}
	}else{
		if(s2[2]==s1[2]-1||s2[2]==s1[2]+1){
			cout<<1;
			return 0;
		}
	}
	cout<<0;
	return 0;
}
