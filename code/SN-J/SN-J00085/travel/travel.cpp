#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int r1,x1;
	string r2,x2;
	cin>>r1>>r2>>x1>>x2;
	if(r1!=x1){
		cout<<"0000";
		return 0;
	}else{
		cout<<'1';
		if(r2[0]==x2[0] and r2[1]==x2[1]){
			cout<<'1';
			if(r2[2]<='C' and x2[2]<='C' or r2[2]>='D' and x2[2]>='D'){
				cout<<'1';
			}else
				cout<<'0';
			if(r2[2]<='C' and x2[2]<='C'){
				if(r2[2]+1==x2[2] or r2[2]==x2[2]+1)
					cout<<'1';
				else
					cout<<'0';
			}else if(r2[2]>'C' and x2[2]>'C')
				cout<<'1';
			else
				cout<<'0';
		}else
			cout<<"000";
	}
	return 0;
} 
