#include<bits/stdc++.h>
using namespace std;
int n,m;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>s1>>m>>s2;
	int t1=(s1[0]-'0')*10+(s1[1]-'0'),t2=(s2[0]-'0')*10+(s2[1]-'0');
	char c1=s1[2],c2=s2[2];
	if(n==m){
		cout<<1;
		if(t1==t2){
			cout<<1;
			if(c1<='C'&&c2<='C'){
				cout<<1;
				if(c1=='B'||c2=='B') cout<<1;
				else cout<<0;
			}
			else if(c1>'C'&&c2>'C'){
				cout<<"11";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
