#include<bits/stdc++.h>
using namespace std;
char a[10],b[10],c[10],d[10];
char ans[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(strcmp(a,c)!=0){
		cout<<"0000";
	}
	else{
		if(b[1]!=d[1]){
			cout<<"1000";
		}
		else{
			if((b[2]>='A' && b[2]<='C' && d[2]>='A' && d[2]<='C') || (b[2]>='D' && b[2]<='F' && d[2]>='D' && d[2]<='F')){
				if((b[2]=='A' && d[2]=='B') || (b[2]=='B' && d[2]=='C') || (b[2]=='D' && d[2]=='F')){
					cout<<"1111";
				}
				else{
					cout<<"1110";
				}
			}
			else{
				cout<<"1100";
			}
		}
	}
	return 0;
} 
