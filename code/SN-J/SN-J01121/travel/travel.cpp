#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3){
		cout<<1;
		string c5="",c6="";
		c5+=c2[0]; c5+=c2[1];
		c6+=c4[0]; c6+=c4[1];
		if(c5==c6){
			cout<<1;
			char c7=c2[2],c8=c4[2];
			if((c7>='A'&&c7<='C'&&c8>='A'&&c8<='C')||(c7>='D'&&c7<='F'&&c8>='D'&&c8<='F')){
				cout<<1;
				if((c7-1==c8||c7+1==c8||c8-1==c7||c8+1==c7)&&(c7!='C'&&c7!='D'&&c8!='C'&&c8!='D')){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0<<0;
			}
		}else{
			cout<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
	cout<<"\n";
	stdin.fclose();
	stdout.fclose();
	return 0;
}
