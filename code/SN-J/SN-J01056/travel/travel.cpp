#include<bits/stdc++.h>
using namespace std;
#define lint long long
char a[10],c[10],b[10],d[10];
bool fla1=0,fla2=0,fla3=0,fla4=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=2;i++){
		cin>>a[i];
	}
	for(int i=1;i<=3;i++){
		cin>>c[i];
	}
	for(int i=1;i<=2;i++){
		cin>>b[i];
	}
	for(int i=1;i<=3;i++){
		cin>>d[i];
	}
	for(int i=1;i<=2;i++){
		if(a[i]!=b[i]){
			fla1=1;
		}
	}
	if(fla1==1){
		cout<<"0000";
	}
	else{
		cout<<"1";
		for(int i=1;i<=2;i++){
			if(c[i]!=d[i]){
				fla2=1;
			}
		}
		if(fla2==1){
			cout<<"000";
		}
		else{
			cout<<"1";
			if(d[3]>c[3]){
				if((d[3]=='D' || d[3]=='E') && (c[3]=='A' || c[3]=='B' || c[3]=='C')){
					fla3=1;
				}
			}
			else{
				if((c[3]=='D' || c[3]=='E') && (d[3]=='A' || d[3]=='B' || d[3]=='C')){
					fla3=1;
				}
			}
			if(fla3==1){
				cout<<"00";
			}
			else{
				cout<<"1";
				if(d[3]>c[3]){
					if(d[3]==c[3]+2){
						fla4=1;
					}
				}
				else{
					if(c[3]==d[3]+2){
						fla4=1;
					}
				}
				if(fla4==1){
					cout<<"0";
				}
				else{
					cout<<"1";
				}
			}
		}
	}
	return 0;
}
