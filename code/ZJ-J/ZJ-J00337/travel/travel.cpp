#include<bits/stdc++.h>
using namespace std;
using ll=long long;
string c1,c2;
string s1,s2;
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
			char p1=s1[2];
			char p2=s2[2];
			if(p1=='A'&&(p2=='B'||p2=='C')){
				cout<<1;
			}else if(p1=='B'&&(p2=='A'||p2=='C')){
				cout<<1;
			}else if(p1=='C'&&(p2=='A'||p2=='B')){
				cout<<1;
			}else if(p1=='D'&&p2=='E'){
				cout<<1;
			}else if(p1=='E'&&p2=='D'){
				cout<<1;
			}else{
				cout<<"00";
				return 0;
			}
			if(p1=='A'&&p2=='B'){
				cout<<1;
			}else if(p1=='B'&&(p2=='A'||p2=='C')){
				cout<<1;
			}else if(p1=='C'&&p2=='B'){
				cout<<1;
			}else if(p1=='D'&&p2=='E'){
				cout<<1;
			}else if(p1=='E'&&p2=='D'){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}