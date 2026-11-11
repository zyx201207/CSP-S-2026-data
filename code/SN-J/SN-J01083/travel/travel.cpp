#include<bits/stdc++.h>
using namespace std;
string c1,a1,c2,a2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>a1>>c2>>a2;
	int a,b;
	int pd1=a1[2];
	int pd2=a2[2];
//	cout<<pd1<<" "<<pd2;
	if(a1[2]=='A'||c1[2]=='B'||a1[2]=='C'){
		a=1;
	}
	else{
		a=2;
	}
	if(a2[2]=='A'||a2[2]=='B'||a2[2]=='C'){
		b=1;
	}
	else{
		b=2;
	}
	if(c1==c2){
		cout<<1;
		if(a1[1]==a2[1]&&a1[0]==a2[0]){
			cout<<1;
			if(a==b){
				cout<<1;
				if(pd1==pd2+1||pd1+1==pd2){
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
