#include<bits/stdc++.h>
using namespace std;
int s1,s2;
string a,b;
int p1,p2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>a>>s2>>b;
	if(s1!=s2){
		cout<<"0000"<<'\n';
		return 0;
	}
	cout<<"1";
	p1=(a[0]-'0')*10+(a[1]-'0');
	p2=(b[0]-'0')*10+(b[1]-'0');
	if(p1!=p2){
		cout<<"000"<<'\n';
		return 0;
	}
	cout<<"1";
	p1=a[2]-'A';
	p2=b[2]-'A';
	if((p1<=2&&p2<=2)||(p1>=3&&p2>=3)){
		if(abs(p1-p2)==1){
			cout<<"11"<<'\n';
			return 0;
		}
		else{
			cout<<"10"<<'\n';
			return 0;
		}
	}
	cout<<"00"<<'\n';
	return 0;
}

