#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b;
	string x,y;
	cin>>a>>x>>b>>y;
	if(a[0]==b[0] && a[1]==b[1]){
		printf("%d",1);
		if((x[0]==y[0]) && (x[1]==y[1])){
			cout<<"1";
			if((x[2]<='C' && x[2]>='A' && y[2]>='A' && y[2]<='C') || (x[2]>='D' && y[2]>='D' && x[2]<='F' && y[2]<='F')){
				printf("%d",1);
				if((x[2]=='D' && y[2]=='F') || (x[2]=='F' && y[2]=='D') || (x[2]=='A' && y[2]=='B') || (x[2]=='B' && y[2]=='A') || (x[2]=='B' && y[2]=='C') || (x[2]=='C' && y[2]=='B')){
					printf("%d",1);
				}
				else{
					printf("%d",0);
					return 0;
				}
			}
			else{
				printf("%d","00");
				return 0;
			}
		}
		else{
			printf("%d","000");
			return 0;
		}
	}
	else{
		printf("%d","0000");
		return 0;
	}
	return 0;
}
