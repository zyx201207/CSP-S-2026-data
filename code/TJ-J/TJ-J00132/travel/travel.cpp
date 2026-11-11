#include<bits/stdc++.h> 

using namespace std;
int main(){
freopen("travel.in","r",stdin);	
freopen("travel.out","w",stdout);
char a[100],b[100];
int c1,c2;
cin>>c1;
for(int i=0;i<3;i++){
	cin>>a[i];
}
cin>>c2;
for(int i=0;i<3;i++){
	cin>>b[i];
}
if(c1==c2){
	if(a[0]==b[0]&&a[1]==b[1]){
		if((a[2]=='D'||a[2]=='F')&&(b[2]=='D'||b[2]=='F')){
			cout<<"1111";
		}
		else if((a[2]=='A'||a[2]=='B'||a[2]=='C')&&(b[2]=='A'||b[2]=='B'||b[2]=='C')){
			if((a[2]=='A'&&b[2]=='B')||(a[2]=='B'&&b[2]=='A')||(a[2]=='B'&&b[2]=='C')||(a[2]=='C'&&b[2]=='B')){
				cout<<"1111";	
			}
			else{
				cout<<"1110";
			}
		}
		else{
			cout<<"1100";
		}
		
	}
	else{
		cout<<"1000";
	}
}
else{
	cout<<"0000";
}
	return 0;
}
