

#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b,c,d;
    string A,B;
    double n,m;
    cin>>a>>A>>b>>B;
    c=(A[0]-'0')*10+A[1]-'0';
    d=(B[0]-'0')*10+B[1]-'0';
    if(a==b){
        cout<<1;
        if(c==d){
			cout<<1;
			if((A[2]=='A'||A[2]=='B'||A[2]=='C')&&(B[2]=='A'||B[2]=='B'||B[2]=='C')){
				cout<<1;
				if((A[2]=='A'&&B[2]=='C')||(A[2]=='C'&&B[2]=='A'))cout<<"0";
				else cout<<1;
			}
			else if((A[2]=='D'&&A[2]=='E')||(B[2]=='D'&&B[2]=='E'))cout<<11;
			else cout<<"00";
        }
        else cout<<"000";

    }
    else cout<<"0000";
    return 0;
}

