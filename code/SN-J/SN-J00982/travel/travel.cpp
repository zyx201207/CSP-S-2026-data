#include<bits/stdc++.h>
using namespace std;
int flag,cc1,cc2;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		flag=1;
	}
	else cout<<0;
	if(flag&&s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
		flag=2;
	}
	else cout<<0;
	if(flag==2){
		if(s1[2]<'D'){
			if(s2[2]<'D'){
				cout<<1;
				flag=3;
			}
			else cout<<0;
		}
		else{
			if(s2[2]>='D'){
				cout<<1;
				flag=3;
			}
			else cout<<0;
		}
	}
	else cout<<0;
	if(flag==3){
		cc1=(int)s1[2];
		cc2=(int)s2[2];
		if(abs(cc1-cc2)==1) cout<<1;
		else cout<<0;
	}
	else cout<<0;
	return 0;
}
