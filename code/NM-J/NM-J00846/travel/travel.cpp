#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string b,d;
	int a,c;
	bool e=0;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1<<endl;
	}else{
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<0<<endl;
		return 0;
		}
	if(b[0]==d[0]&&b[1]==d[1]){
		cout<<1<<endl;
	}else{
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<0<<endl;
		return 0;
		}
	if(b[2]<='C'&&d[2]<='C'){
		cout<<1<<endl;
		e=1;
	}else{
		if(b[2]<='F'&&d[2]<='F'&&b[2]>'C'&&d[2]>'C'){
			cout<<1<<endl;
			e=1;
		}else{
			cout<<0<<endl;
			cout<<0<<endl;
			return 0;
			}
		}
	if(e==1){
		if(b[2]+1==d[2]||b[2]-1==d[2]){
			cout<<1<<endl;
			}else{
			cout<<0<<endl;
			}
	}else{
		cout<<0<<endl;
		}
return 0;
}
