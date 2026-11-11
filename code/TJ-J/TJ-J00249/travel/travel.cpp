#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
		return 0;
	}else cout<<1;
	int x=(b[0]-'0')*10+b[1]-'0';
	int y=(d[0]-'0')*10+d[1]-'0';
	if(x!=y){
		cout<<"000";
		return 0;
	}else cout<<1;
	if((b[2]<='C'||d[2]<='C')){
		cout<<1;
		if(b[2]-'A'==d[2]-'A'+1||b[2]-'A'+1==d[2]-'A'){
			cout<<1;
		}else cout<<0;
	}else if((b[2]>='D'||d[2]>='D')){
		cout<<11;
	}else{
		cout<<00;
	}
	return 0;
}
