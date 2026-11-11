#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,c;
	string b,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
	}else{
		for(int i=0;i<4;i++){
			cout<<0;
		}
		return 0;
	}
	if(b.substr(0,2)==d.substr(0,2)){
		cout<<1;
	}else{
		for(int i=0;i<3;i++){
			cout<<0;
		}
		return 0;
	}
	if(b[2]<'D'&&d[2]<'D'){
		cout<<1;
	}else{
		cout<<0<<0;
		return 0;
	}
	if(abs(b[2]-d[2])==1){
		cout<<1;
	}else{
		cout<<0;
		return 0;
	}
	return 0;
}
