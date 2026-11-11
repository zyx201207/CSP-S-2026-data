#include<bits/stdc++.h>
using namespace std;
string a1,a2;
string b1,b2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2;
	cin>>b1>>b2;
	if(a1=="01"||b1=="01"||a1=="16"||b1=="16"){
		cout<<"0000"<<'\n';
		return 0;
	}
	if(a1==b1){
		cout<<'1';
		if(a2[0]==b2[0]&&a2[1]==b2[1]){
			cout<<'1';
			long long x=a2[2]-'A';
			long long y=b2[2]-'A';
			if((x<3&&y<3)||(x>2&&y>2)){
				cout<<'1';
				if(abs(x-y)==1){
					cout<<'1';
				}else{
					cout<<'0';
				}
			}else{
				cout<<"00"<<'\n';
			}
		}else{
			cout<<"000"<<'\n';
		}
	}else{
		cout<<"0000"<<'\n';
	}
	return 0;
}
