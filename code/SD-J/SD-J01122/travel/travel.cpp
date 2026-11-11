#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf=0x3f3f3f3f;
const i64 INF=0x3f3f3f3f3f3f3f3f;
string c1,s1,c2,s2; 
void solve(){
	cin>>c1>>s1>>c2>>s2;
	if(c1=="01"||c1=="16"||c2=="01"||c2=="16"){
		cout<<"0000";
		return ;
	}
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<"0000";
		return ;
	}
	int pia1=0,pia2=0;
	for(int i=0;i<2;i++){
		pia1=pia1*10+s1[i]-'0';
	}
	for(int i=0;i<2;i++){
		pia2=pia2*10+s2[i]-'0';
	}
	if(pia1==pia2){
		cout<<1;
	}
	else{
		cout<<"000";
		return ;
	}
	int flag1,flag2;
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
		flag1=1;
	}
	else{
		flag1=2;
	}
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
		flag2=1;
	}
	else{
		flag2=2;
	}
	if(flag1==flag2){
		cout<<1;
	}
	else{
		cout<<"00";
		return ;
	}
	bool flag=1;
	if(flag1==2){
		cout<<1;
		flag=0;
	}
	else{
		if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')){
			cout<<1;
			flag=0;
		}
		if((s2[2]=='A'&&s1[2]=='B')||(s2[2]=='B'&&s1[2]=='C')){
			cout<<1;
			flag=0;
		}
	}
	if(flag){
		cout<<0;
	}
} 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	solve();
	return 0;
}
