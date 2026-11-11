#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	//1
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	int t1,t2;
	t1=(s1[0]-'0')*10+s1[1]-'0';
	t2=(s2[0]-'0')*10+s2[1]-'0';
	//2ÅÅ 
	if(t1==t2){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	} 
	//3£¬4 
	if((s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='C')){
		cout<<0<<0;
		return 0;
	}else{
		cout<<1;
		if((s1[2]=='A'&&s2[2]=='C')||(s2[2]=='A'&&s1[2]=='C')){
			cout<<0;
		}else{
			cout<<1;
		}
	}
	return 0;
} 
