#include<bits/stdc++.h>
using namespace std;
#define int long long
bool tx=false;
bool tp=false;
bool tc=false;
bool xl=false;
string c1,s1,c2,s2;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		tx=true;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		tp=true;
	}else{
		cout<<1<<0<<0<<0;
		return 0;
	}
	if((s1[2]=='A'&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||(s1[2]=='C'&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))){
		tc=true;
	}else if((s1[2]=='D'&&(s2[2]=='D'||s2[2]=='F'))||(s1[2]=='F'&&(s2[2]=='D'||s2[2]=='F'))){
		tc=true;
	}else{
		cout<<1<<1<<0<<0;
		return 0;
	}
	if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='C'&&s2[2]=='B')||((s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C'))){
		xl=true;
	}else if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
		xl=true;
	}else{
		cout<<1<<1<<1<<0;
		return 0;
	}
	if(tx){
		cout<<1;
	}else if(!tx){
		cout<<0;
	}
	if(tp){
		cout<<1;
	}else if(!tp){
		cout<<0;
	}
	if(tc){
		cout<<1;
	}else if(!tc){
		cout<<0;
	}
	if(xl){
		cout<<1;
	}else if(!xl){
		cout<<0;
	}
	return 0;
} 
