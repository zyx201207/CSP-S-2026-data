#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
int a[5],b[5],f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel,out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	for(int i=0;i<=sizeof c1;i++) a[i+1]=c1[i]-'0';
	for(int i=0;i<=sizeof c3;i++) b[i+1]=c3[i]-'0';
	for(int i=1;i<=2;i++){
		if(a[i]!=b[i]){
			cout<<"0000";
			return 0;
		}
	}
	cout<<1;
	for(int i=0;i<=1;i++) a[i+1]=c2[i]-'0';
	for(int i=0;i<=1;i++) b[i+1]=c4[i]-'0';
	for(int i=1;i<=2;i++)
		if(a[i]!=b[i]){
			cout<<"000";
			return 0;
		}
	cout<<1;		
	
	if((c2[2]>='A'&&c2[2]<='C'&&c4[2]>='A'&&c4[2]<='C')||(c2[2]>='D'&&c2[2]<='F'&&c4[2]>='D'&&c4[2]<='F'))
		cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(c2[2]>='D')
		cout<<1;
	else if(abs(int(c2[2]-c4[2]))==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
