#include<bits/stdc++.h>
using namespace std;
char a,b;
string a1,b1;
int s=1,z=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a1>>b>>b1;
	if(a==b){
		cout<<s;
		if(a1[0]==b1[0] || a1[1]==b1[1]){
			cout<<s;
			if(a1[2]<='C' || a1[2]>='A' || b1[2]<='C' || b1[2]>='A'){
				cout<<s;
				int i=a1[2],j=b1[2];
				if(i+1==j or i-1==j){
					cout<<s;
				}
				else{
					cout<<z;
				}
			}
			else if((a1[2]<='F' && a1[2]>='D') && (b1[2]<='F' && b1[2]>='D')){
				cout<<s<<s;
			}
			else{
				cout<<z;
			}
		}
		else{
			cout<<z<<z;
		}
	}
	else{
		cout<<z<<z<<z;
	}
	
	return 0;
}
