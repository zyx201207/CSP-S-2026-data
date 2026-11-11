#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second

bool kkk(string c1,string c2){
	if(c1[2]>='D'){
		if(c2[2]>='D')return 1;
		return 0;
	}
	if(c2[2]<='C'){
		return 1;
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1!=s3){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(s2[0]!=s4[0]||s2[1]!=s4[1]){
		cout<<"000";
		return 0;
	}
	cout<<1;
	if(!kkk(s2,s4)){
		cout<<"00";
		return 0;
	}
	cout<<1;
	if(s2[2]+1==s4[2]||s4[2]+1==s2[2]){
		cout<<1;
		return 0;
	}
	cout<<0;
}
