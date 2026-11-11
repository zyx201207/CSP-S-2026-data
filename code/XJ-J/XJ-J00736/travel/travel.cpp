#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("travel","r",stdin);
	//freopen("travel","w",stdout);
	int n,m;
	string a,b;
	cin>>n>>a>>m>>b;
	if(n==m)
		cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(a[0]==b[0]&&a[1]==b[1]){
		cout<<1;
	}
	else
		cout<<0;
	if(a[0]==b[0]&&a[1]==b[1]&&(a[2]<'D'&&b[2]<'D')||(a[2]>='D'&&b[2]>='D'))
		cout<<1;
	else
		cout<<0;
	if(a[0]==b[0]&&a[1]==b[1]&&(a[2]<'D'&&b[2]<'D')||(a[2]>='D'&&b[2]>='D')){
		if(a[2]=='A'&&b[2]=='B'){
			cout<<1;
			return 0;
		}
		if(a[2]=='B'&&(b[2]=='A'||b[2]=='C')){
			cout<<1;
			return 0;
		}
		if(a[2]=='C'&&b[2]=='B'){
			cout<<1;
			return 0;
		}
		if(a[2]=='D'&&b[2]=='E'){
			cout<<1;
			return 0;
		}
		if(a[2]=='E'&&b[2]=='D'){
			cout<<1;
			return 0;
		}
	}
	cout<<0;
	return 0;
}