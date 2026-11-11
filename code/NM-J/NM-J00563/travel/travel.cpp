#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool flag=0,flag1=0,flag2=0;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;

    if(a==c){
    	flag=1;
    	cout<<1;
	}
	else cout<<0;

    if(b[0]==d[0]&&b[1]==d[1]&&flag){
    	flag1=1;
    	cout<<1;
	}
	else cout<<0;

    if((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C')&&flag1
       || (b[2]=='F'||b[2]=='D')&&(d[2]=='F'||d[2]=='D')&&flag1){
        flag2=1;
        cout<<1;
    }
    else{
        cout<<0;
    }

    if(abs(b[2]-d[2])==1&&flag2)cout<<1;
    else cout<<0;

    return 0;
}
