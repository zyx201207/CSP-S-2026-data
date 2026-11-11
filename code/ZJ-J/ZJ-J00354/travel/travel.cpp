#include<bits/stdc++.h>
using namespace std;
string c,cc,ccc,cccc;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>cc>>ccc>>cccc;
	if(c==ccc){
		cout<<1;
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	if(cc[0]==cccc[0]&&cc[1]==cccc[1]){
		cout<<1;
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	if(cc[0]==cccc[0]&&cc[1]==cccc[1]){
		if(cc[2]<='C'&&cccc[2]<='C'){
			cout<<1;
			if(abs(int(cc[2]-cccc[2]))==1) cout<<1;
			else cout<<0;
		}else if(cc[2]<='F'&&cccc[2]<='F'&&cc[2]>='D'&&cccc[2]>='D'){
			cout<<1;
			if(abs(int(cc[2]-cccc[2]))==1) cout<<1;
			else cout<<0;
		}else{
			cout<<0;
			cout<<0;
			return 0;
		}
	}
	return 0;
}
