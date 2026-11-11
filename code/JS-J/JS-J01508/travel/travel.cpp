#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	if(a1!=b1){
		cout<<"0000"<<endl;
		return 0;
	}
	if(a2[0]!=b2[0]||a2[1]!=b2[1]){
		cout<<"1000"<<endl;
		return 0;
	}
	if((a2[2]<'D'&&b2[2]>='D')||(a2[2]>='D'&&b2[2]<'D')){
		cout<<"1100"<<endl;
	}
	int l=(int)(a2[2]-'A');
	int r=(int)(b2[2]-'B');
	if(abs(r-l)>1){
		cout<<"1110"<<endl;
		return 0;
	}
	cout<<"1111"<<endl;
	return 0;
}
