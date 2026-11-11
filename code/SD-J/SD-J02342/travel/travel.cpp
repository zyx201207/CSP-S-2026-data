#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2;
int a1,a2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(s1[2]=='D'||s1[2]=='F'){
		a1=2;
	}else{
		a1=1;
	}if(s2[2]=='D'||s2[2]=='F'){
		a2=2;
	}else{
		a2=1;
	}if(a1==a2){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(a1==1&&(s1[2]=='B'||s2[2]=='B')){
		cout<<1;
	}else cout<<0;
	if(a1==2){
		cout<<1;
	}
	return 0;
}
