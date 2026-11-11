#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
int main(){
	preopen("travel.in","r",stdin);
	preopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	bool f1=0,f2=0,f3=0,f4=0;
	if(c1[0]==c3[0]&&c1[1]==c3[1]){
		f1=1;
	}
	if(f1==1){
		if(c2[0]==c4[0]&&c2[1]==c4[1]){
			f2=1;
			if(c2[2]>='A'&&c2[2]<='C'&&c4[2]>='A'&&c4[2]<='C'){
				f3=1;
			}
			if(c2[2]>='D'&&c2[2]<='F'&&c4[2]>='D'&&c4[2]<='F'){
					f3=1;
			}
				
		}
	}
	if(f3==1){
		if(c2[2]+1==c4[2]||c2[2]-1==c4[2]){
			f4=1;
		}
	}
	cout<<f1<<f2<<f3<<f4;
	
	return 0;
}
