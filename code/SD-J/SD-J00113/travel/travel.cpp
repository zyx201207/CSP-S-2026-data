#include<bits/stdc++.h>
using namespace std;
int a[10]={1,1,1,0,0};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cx1,cx2,sx1,sx2;	
	cin>>cx1>>sx1>>cx2>>sx2;
	if(sx1[2]=='F'){
		sx1[2]='E';
	}
	if(sx2[2]=='F'){
		sx2[2]='E';
	}
	if(cx1==cx2){
		cout<<1;
		if(sx1[0]==sx2[0]&&sx1[1]==sx2[1]){
			cout<<1;
			if(a[sx1[2]-'A']==a[sx2[2]-'A']){
				cout<<1;
				if(abs(sx1[2]-sx2[2])==1){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<"00";
			}
			
		}
		else{
			cout<<"000";
		}
			
	}
	else{
		cout<<"0000";
	}
	return 0;
} 
