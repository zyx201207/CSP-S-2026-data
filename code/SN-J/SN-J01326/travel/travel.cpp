#include<bits/stdc++.h>
using namespace std;

char a[10];


int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=0;i<10;i++){
		cin>>a[i];
	}
	if(a[0]==a[5]||a[1]==a[6]){
		cout<<1;
		if(a[2]==a[7]||a[3]==a[8]){
			cout<<1;
			
			int x=a[4];
			int y=a[9];
			if(abs(x-y)<=2){
				cout<<1;
				
				if(abs(x-y)==1){
					
					if(x==67&&y==68){
						cout<<0;
					}
					else if(x==68&&y==67){
						cout<<0;
					}
					else{
						cout<<1;
					}
				}
				else if(x==68||y==69){
					cout<<1;
				}
				else if(x==69||y==68){
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
		return 0;
	}
	
	
	
	
	return 0;
}
