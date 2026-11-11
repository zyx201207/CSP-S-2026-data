#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c&&a!="01"&&a!="016"){
		cout<<"1";
		if(b.size()!=d.size()){
			cout<<"000";
		}
		else{
			bool e=1;
			int f=b.size()-1;
			for(int i=1;i<=b.size();i++){
				if(b[i]>='0'&&b[i]<='9'){
					if(b[i]!=d[i]){
						e=0;
					}
				}
			}
			if(!e){
				cout<<"000";
			}
			else{
				cout<<"1";
				if((b[f]=='C'&&d[f]=='D')||(b[f]=='D'&&d[f]=='C')){
					cout<<"00";
				}
				else{
					cout<<"1";
					if(int(b[f])+1==int(d[f])||int(b[f])-1==int(d[f])){
						cout<<"1";
					}
					else{
						cout<<"0";
					}
				}
			}
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
