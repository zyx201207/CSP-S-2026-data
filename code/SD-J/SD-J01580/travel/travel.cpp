#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,c;
	char b[5],d[5];
	cin>>a;
	for(int i=0;i<3;i++){
		cin>>b[i];
	}
	cin>>c;
	for(int i=0;i<3;i++){
		cin>>d[i];
	}
	int q1=0,q2=0,q3=0,q4=0;
	if(a==c){
		q1=1;
		if(b[0]==d[0]&&b[1]==d[1]){
			q2=1;
			if(b[2]>='D'&&d[2]>='D'){
				q3=1;
			}
			if(b[2]<='C'&&d[2]<='C'){
				q3=1;
				if(b[2]=='A'&&d[2]=='C'||b[2]=='C'&&d[2]=='A'){
					q4=0;
				}
				else{
					q4=1;
				}
			}
		}
	}
	cout<<q1<<q2<<q3<<q4;
	return 0;
} 
