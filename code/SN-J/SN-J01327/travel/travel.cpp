#include<bits/stdc++.h>
using namespace std;

string ar,ax;
char br[5],bx[5];
int q1=0,q2=0,q3=0,q4=0;

int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>ar>>br[0]>>br[1]>>br[2]>>ax>>bx[0]>>bx[1]>>bx[2];
	int brint=int(br[2]);
	int bxint=int(bx[2]);
	
	if(ar==ax){
		cout<<'1';
		q1=1;
	}
	else{cout<<'0';}
	
	
	if(q1==1){
		if(br[0]==bx[0] && br[1]==bx[1]){
			cout<<'1';
			q2=1;
		}
		else{cout<<'0';}
	}
	else{cout<<'0';}
	
	
	if(q1==1 && q2==1){
		if( (br[2]=='A'||br[2]=='B'||br[2]=='C') && (bx[2]=='A'||bx[2]=='B'||bx[2]=='C') ){
			cout<<'1';
			q3=1;
		}
		else if( (br[2]=='D'||br[2]=='F') && (bx[2]=='D'||bx[2]=='F') ){
			cout<<'1';
			q3=1;
		}
		else{cout<<'0';}
	}
	else{cout<<'0';}
	
	
	if(q1==1 && q2==1 && q3==1){
		if(brint==bxint+1 || brint==bxint-1)
		{
			if( (br[2]=='C' && bx[2]=='D') || (br[2]=='D' && bx[2]=='C') ){
				cout<<'0';
				return 0;
			}
			else{
				cout<<'1';
				return 0;
			}
			
		}
		else{cout<<'0';}
    }
    else{cout<<'0';}
    
    
return 0;
}
