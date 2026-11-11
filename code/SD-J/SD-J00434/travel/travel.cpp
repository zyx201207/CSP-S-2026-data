#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		string x="",y="";
		for(int k=0;k<2;k++){
			x+=s1[k];
			y+=s2[k];
		}
		
		if(x==y){
			cout<<1;
			char a=s1[2],b=s2[2];
			if((a>='A'&&b<='C')||(a>='D'&&b<'F')){
				cout<<1;
				int i=int(a),j=int(b);
				if(abs(i-j)==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
