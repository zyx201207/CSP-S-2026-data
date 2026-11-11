#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
char x,y;
int main(){
	freopen("travel.in ","r",stdin);
	freopen("travel.out","w",stdout);

//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		bool fl=1;
		for(int i=0;i<2;i++){
			if(b[i]!=d[i]){
				fl=0;
			}
		}
		if(fl){
			bool ff=0;
			cout<<1;
			if(b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C'){
				cout<<1;
				ff=1;
			}else if(b[2]>='D'&&b[2]<='F'&&d[2]>='D'&&d[2]<='F'){
				cout<<1;
				ff=1;
			}else{
				cout<<"00";
			}
			if(ff){
				if(b[2]>'A'&&b[2]<'F'){
					if(b[2]-1==d[2]||b[2]+1==d[2]){
						cout<<1;
					}else{
						cout<<0;
					}
				}else if(b[2]=='A'){
					if(b[2]+1==d[2]){
						cout<<1; 
					}else{
						cout<<0;
					}
				}else{
					if(b[2]-1==d[2]){
						cout<<1;
					}else{
						cout<<0;
					}
				}
			}
		}else{
			cout<<"000";
		}
		
		
	}else{
		cout<<"0000"; 
	}
	return 0;
} 
