#include<bits/stdc++.h>
using namespace std;
int a,b,c;
string n,m,x,y;
int s[100005];
bool N=false,M=false,X=false,Y=false;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> n >> m >> x >> y;
	if(n==x){
		N=true;
	}
	else{
		printf("%d%d%d%d",N,M,X,Y);	
		return 0;	
	} 
	if(m[0]==y[0]&&m[1]==y[1]){
		M=true;
	}
	else{
		printf("%d%d%d%d",N,M,X,Y);	
		return 0;	
	}	
	if((m[2]=='D'||m[2]=='F')&&(y[2]=='D'||y[2]=='F')){
		X=true;
		Y=true;
	}
	else if((m[2]=='A'||m[2]=='B'||m[2]=='C')&&(y[2]=='A'||y[2]=='B'||y[2]=='C')){
		X=true;		
	}
	else{
		printf("%d%d%d%d",N,M,X,Y);	
		return 0;	
	}
	if(((m[2]=='A'||m[2]=='B'||m[2]=='C')&&(y[2]=='A'||y[2]=='B'||y[2]=='C'))&&((m[2]!='A'||m[2]!='C')&&(y[2]!='A'||y[2]!='C'))){
		Y=true;
	}
	else{
		printf("%d%d%d%d",N,M,X,Y);	
		return 0;	
	}	
	printf("%d%d%d%d",N,M,X,Y);
	return 0;
}
