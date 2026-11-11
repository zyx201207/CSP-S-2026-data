#include<bits/stdc++.h>
using namespace std;
int a,b,f=0;
char c[101],d[101];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a;
	for(int i=1;i<=3;i++){
		cin>>c[i];
	}
	cin>>b;
	for(int i=1;i<=3;i++){
		cin>>d[i];
	}
	if(a==b){
		cout<<1;
		f=1;
	}else{
		cout<<0;
	}
	if(c[1]==d[1]&&c[2]==d[2]&&f==1){
		cout<<1;
	}else{
		cout<<0;
	}
	if((c[1]==d[1]&&c[2]==d[2])&&( ( (c[3]=='A'||c[3]=='B'||c[3]=='C')&&(d[3]=='A'||d[3]=='B'||d[3]=='C') ) ||((c[3]=='F'||c[3]=='D')&&(d[3]=='F'||d[3]=='D')) )&&f==1){
		cout<<1;
	}else{
		cout<<0;
	}
	if((c[3]=='A'||c[3]=='B'||c[3]=='C')&&(d[3]=='A'||d[3]=='B'||d[3]=='C')&&f==1){
		if(c[3]+1==int(d[3])){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(((c[3]=='F'||c[3]=='D')&&(d[3]=='F'||d[3]=='D'))&&f==1){
		if(c[3]+1==int(d[3])){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	return 0;
} 
