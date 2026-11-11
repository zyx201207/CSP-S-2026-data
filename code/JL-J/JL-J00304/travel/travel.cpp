#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
	}
	else{
		cout<<"1";
		for(int i=0;i<=1;i++){
			if(b[i]!=d[i]){
				cout<<"000";
				return 0;
			}
		}
		cout<<"1";
		if((b[2]-'A'+1<=3&&d[2]-'A'+1<=3)||(b[2]-'A'+1>=4&&d[2]-'A'+1>=4)){
			cout<<"1";
		}else{
			cout<<"00";
			return 0;
		}
		if(abs(b[2]-d[2])==1)cout<<"1";
		else cout<<"0";
	}
	return 0;
}
