#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a[10];
	cin>>a[1]>>a[2]>>a[3]>>a[4];
	if(a[1]!=a[3]){
		cout<<"0000";
		
	}
	else{
		cout<<1;
		if(a[2][0]!=a[4][0]||a[2][1]!=a[4][1]){
			cout<<"000";
		}
		else{
			cout<<1;
			if((a[2][2]<='C'&&a[4][2]>'C')||(a[2][2]>'C'&&a[4][2]<='C')){
				cout<<"00";
			}
			else{
				cout<<1;
				if((a[2][2]=='D'&&a[4][2]=='F')||(a[2][2]=='F'&&a[4][2]=='D')||(a[2][2]<'C'&&a[2][2]+1==a[4][2])||(a[2][2]>'A'&& a[2][2]-1==a[4][2])){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}		
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
