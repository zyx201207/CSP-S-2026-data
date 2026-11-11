#include<bits/stdc++.h>
using namespace std;
string n,m,x,y,r,j;
int main(){
	freopen("travel.in","w",stdin);
	freopen("travel.out","d",stdout);
	cin>>n>>m>>x>>y;
	if(n==x){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<3;i++){
		if(m[i]<='9'&&m[i]>='0'){
			r[i]=m[i];
		}
	}
	for(int i=0;i<3;i++){
		if(y[i]<='9'&&y[i]>='0'){
			j[i]=y[i];
		}
	}
	bool k=1;
	for(int i=0;i<2;i++){
		if(r[i]!=j[i]){
			k=0;
		} 
	}
	if(k==1){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	if(m[2]<='C'&&m[2]>='A'&&y[2]<='C'&&y[2]>='A'){
		cout<<"1";
		if(m[2]+1==y[2]||m[2]-1==y[2]){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	else if(m[2]<='E'&&m[2]>='D'&&y[2]<='E'&&y[2]>='D'){
		cout<<"11";
	}
	else{
		cout<<"00";
	}
	return 0;
} 
