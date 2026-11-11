#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a;string c;string d;string b;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		string bb=b.substr(0,2),dd=d.substr(0,2);
		if(bb==dd){
			cout<<1;
			if(b[2]<='C'&&d[2]<='C'){
				if(abs(int(b[2]-d[2])<=1))cout<<"11";
				else cout<<"10";
			}else if(b[2]>='D'&&d[2]>='D'){
				cout<<11;
			}else cout<<"00";
		}
		else cout<<"000";
	}else cout<<"0000";
	return 0; 
}

