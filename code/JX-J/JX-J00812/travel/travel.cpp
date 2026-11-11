#include<bits/stdc++.h>
using namespace std;
char a[5],b[5],c[5],d[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=2;i++){
		cin>>a[i];
	}
	for(int i=1;i<=3;i++){
		cin>>b[i];
	}
	for(int i=1;i<=2;i++){
		cin>>c[i];
	}
	for(int i=1;i<=3;i++){
		cin>>d[i];
	}
	if(a[2]==c[2]){
		cout<<"1";
		if(b[2]==d[2]){
			cout<<"1";
			if(b[3]=='A'||b[3]=='B'||b[3]=='C'){
				if(d[3]=='A'||d[3]=='B'||d[3]=='C'){
					cout<<"1";
					if(abs(int(b[3]-d[3]))==1){
						cout<<"1";
					}
					else{
						cout<<"0";
					}
				}
				else{
					cout<<"00";
				}
			}
			else{
				if(d[3]=='A'||d[3]=='B'||d[3]=='C'){
					cout<<"00";
				}
				else{
					cout<<"1";
					if(abs(int(b[3]-d[3]))==1){
						cout<<"1";
					}
					else{
						cout<<"0";
					}
				}
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
}
