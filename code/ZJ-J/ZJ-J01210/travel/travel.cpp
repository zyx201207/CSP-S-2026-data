#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	if(a1!=b1){
		cout<<"0000"<<endl;
		return 0;
	}else{
		cout<<1;
	}
	if(a2[0]==b2[0]&&a2[1]==b2[1]){
		cout<<1;
	}else{
		cout<<"000"<<endl;
		return 0;
	}
	if(a2[2]=='F'&&b2[2]=='D'||a2[2]=='F'&&b2[2]=='D'){
		cout<<"11";
		return 0;
	}else if(a2[2]=='F'&&b2[2]!='D'){
		cout<<"00";
		return 0;
	}else if(a2[2]=='D'&&b2[2]!='F'){
		cout<<"00";
		return 0;
	}else if(b2[2]=='F'&&a2[2]!='D'){
		cout<<"00";
		return 0;
	}else if(b2[2]=='D'&&a2[2]!='F'){
		cout<<"00";
		return 0;
	}else{
		cout<<1;
	}
	if(a2[2]-b2[2]==1||a2[2]-b2[2]==-1||a2[2]=='F'&&b2[2]=='D'||a2[2]=='F'&&b2[2]=='D'){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
