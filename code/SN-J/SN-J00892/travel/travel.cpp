#include<bits/stdc++.h>
using namespace std;
int a,c;
string b,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a!=c||(a==16||c==16)||(a==01||c==01)){
		cout<<"0000";
	}else{
	for(int i=0;i<2;i++){
		if(b[1]!=d[1]){
			cout<<"1000";
			break;
		}else{
			if((b[2]<='C'&&d[2]<='C')||(b[2]>='D'&&b[2]<='F'&&d[2]>='D'&&d[2]<='F')){
				if(b[2]+1==d[2]){
					cout<<"1111";
				break;
			}else{
				cout<<"1110";
				break;
			}cout<<"1110";
				
		}else{
			cout<<"1100";
			break;
		}
		}break;
	}}return 0;
}
