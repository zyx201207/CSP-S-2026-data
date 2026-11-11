#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
string m,n,x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	m=b.substr(0,2);
	n=d.substr(0,2);
	if(m==n){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	x=b.substr(2,1);
	y=d.substr(2,1);
	if(x=="A"){
		if(y=="B"){
			cout<<"11";
			return 0;
		}else if(y=="C"){
			cout<<"10";
			return 0;
		}else{
			cout<<"00";
		}
	}else if(x=="B"){
		if(y=="A"){
			cout<<"11";
			return 0;
		}else if(y=="C"){
			cout<<"11";
			return 0;
		}else{
			cout<<"00";
		}
	}else if(x=="C"){
		if(y=="B"){
			cout<<"11";
			return 0;
		}else if(y=="A"){
			cout<<"10";
			return 0;
		}else{
			cout<<"00";
		}
	}if(x=="D"){
		if(y=="F"){
			cout<<"11";
			return 0;
		}else{
			cout<<"00";
			return 0;
		}
	}if(x=="F"){
		if(y=="D"){
			cout<<"11";
			return 0;
		}else{
			cout<<"00";
			return 0;
		}
	}
	return 0;
}
