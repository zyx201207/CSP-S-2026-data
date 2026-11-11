#include<bits/stdc++.h>
using namespace std;



int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		string e,f;
		e=b[0]+b[1];
		f=d[0]+d[1];
		if(e==f) {
			cout<<1;
			e=b[2];
			f=d[2];
			if(e[0]<='C'&&f[0]<='C'||e[0]>='D'&&f[0]>='D'){
				cout<<1;
				if(abs(e[0]-f[0])==1){
					cout<<1;
				}
				else cout<<0;
			}
			else cout<<"00";
		}
		else{
			cout<<"000";
		}
	} 
	else cout<<"0000";
	
	
	
	return 0;
}
