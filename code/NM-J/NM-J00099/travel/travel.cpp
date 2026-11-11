#include<bits/stdc++.h>
using namespace std;
long long a,b;
string A,B;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>a>>A>>b>>B;
    if(a==b) 
	    cout<<1;
    else
	    cout<<0; 
    if(A[0]==B[0]&&A[1]==B[1]) 
	    cout<<1;
    else 
	    cout<< 0;
	    int cnt=0;
    if(A[0]==B[0]&&A[1]==B[1]) {
    	if(A[2]=='A'||A[2]=='B'||A[2]=='C'){
    		if(B[2]=='A'||B[2]=='B'||B[2]=='C'){
    			cout<<1;
    			cnt = 1;
			}
			else cout<<0;
		}
		else{
			if(B[2]=='D'||B[2]=='F'){
			    cout<<1;
			    cnt =2;
			}
			else cout<<0;
		}
	}
	if(cnt =1){
		if(A[2]=='A'&&B[2]=='B') cout<<1;
		else if(A[2]=='B'&&B[2]=='C') cout<<1;
		else if(A[2]=='B'&&B[2]=='A') cout<<1;
		else if(A[2]=='C'&&B[2]=='B') cout<<1;
		else cout<<0;
	}
	else if(cnt =2) cout<<1;
	else cout<<0;
    return 0;
}
