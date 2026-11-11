#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string c,d;
	cin>>a>>c>>b>>d;
	if(a!=b){
		cout<<"0000";
		return 0;
	}
	else{
		int w=0,e=0;
		for(int i=0;i<=1;i++){
			e=e*10+int(d[i]-'0');
			w=w*10+int(c[i]-'0');
		}
		if(e!=w){
			cout<<"1000";
			return 0;
		}
		else{
			if(((c[2]<='C'&&d[2]<='C')||(c[2]>'C'&&d[2]>'C'))){
				if((c[2]<='C'&&d[2]<='C')){
					if(abs(c[2]-d[2])==1){
						cout<<"1111";
						return 0;
					}
					else{
						cout<<"1110";
						return 0;
					}
				}
				else{
					cout<<"1111";
					return 0;
				}
			}
			else{
				cout<<"1100";
				return 0;
			}
		}
	}
	return 0;
}
