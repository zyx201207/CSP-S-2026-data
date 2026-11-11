#include<bits/stdc++.h>
using namespace std;
int na,nb,ma,mb;
char ca,cb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>na>>ma>>ca>>nb>>mb>>cb;
	if(na!=nb){
		cout<<"0000";
	}
	else if(ma!=mb){
		cout<<1000;
	}
	else if(ca<'D'!=cb<'D'){
		cout<<1100;
	}
	else if(abs((ca-(ca=='E'))-(cb-(cb=='E')))!=1){
		cout<<1110;
	}
	else cout<<1111;
	return 0;
}