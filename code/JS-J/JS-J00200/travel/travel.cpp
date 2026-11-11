#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	char a[4];
	char b[4];
	for(int i=0;i<3;i++){
		a[i]=s1[i];
		b[i]=s2[i];
		
	}
	if(a[0]==b[0]&&a[1]==b[1]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if(a[2]=='A'||a[2]=='B'||a[2]=='C'&&b[2]=='A'||b[2]=='B'||b[2]=='C'&&a[2]!=b[2]){
		cout<<"1";
	}else if(a[2]=='D'||a[2]=='F'&&b[2]=='D'||b[2]=='F'&&a[2]!=b[2]){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if(a[2]=='A'&&b[2]=='B'||a[2]=='B'&&b[2]=='A'||a[2]=='B'&&b[2]=='C'||a[2]=='C'&&b[2]=='B'||a[2]=='D'&&b[2]=='F'||a[2]=='F'&&b[2]=='D'){
		cout<<"1";
	}else{
		cout<<"0";
		return 0;
	}
	return 0;
}
