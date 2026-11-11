#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,c;
	char bs[1000];
	char ds[1000];
	cin>>a;
	for(int i=1;i<=3;i++){
		cin>>bs[i];
	}
	cin>>c;
	for(int i=1;i<=3;i++){
		cin>>ds[i];
	}
	if(a==c){
		cout<<1;
	}else{
		cout<<0;
			}
	if(a==c){
		if(bs[1]==ds[1]){
			if(bs[2]==ds[2]){
				cout<<1;
			}
		}else{
			cout<<0;
		}
		if(bs[1]==ds[1]){
			if(bs[2]==ds[2]){
				if((bs[3]=='A'&&ds[3]=='B')||(bs[3]=='A'&&ds[3]=='C')||(bs[3]=='B'&&ds[3]=='C')||(bs[3]=='D'&&ds[3]=='F')){
					cout<<1;			
				}else{
					cout<<0;
				}
				if((bs[3]=='A'&&ds[3]=='B')||(bs[3]=='B'&&ds[3]=='C')||(bs[3]=='D'&&ds[3]=='F')){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<"000";
				return 0;
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"000";
	}
	
}
