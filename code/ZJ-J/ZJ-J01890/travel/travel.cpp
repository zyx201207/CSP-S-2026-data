#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	else cout<<1;
	if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		cout<<"000";
		return 0;
	}
	else cout<<1; 
	char ch1=s1[2],ch2=s2[2];
	if(ch1=='C'&&ch2=='D'||ch1=='D'&&ch2=='C'){
		cout<<"00";
		return 0;
	}
	else cout<<1;
	if(abs(ch1-ch2)!=1)cout<<0;
	else cout<<1;
	return 0;
} 
