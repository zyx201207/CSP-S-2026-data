#include<bits/stdc++.h>
using namespace std;
string a,a1,b,b1;
char l,z;
char i,j;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a1>>b>>b1;
	if(a==b){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	l=a1[0]+a1[1];
	z=b1[0]+b1[1];
	if(l==z){
		cout<<1;
		i=a1[2];
		j=b1[2];
		if(i<'D'){
			if(j<'D'){
				cout<<1;
				if(int(i-j)==1||int(j-i)==1){
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
			if(j>='D'){
				cout<<"11";
			}
			else{
				cout<<"00";
			}
		}
	}
	else{
		cout<<"000";
	}
	
	return 0;
} 
