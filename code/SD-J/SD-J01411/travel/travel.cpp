#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int p1,p2;
	int sum=0;
	char t1[10001];
	char t2[10001];
	cin>>p1;
	cin>>t1;
	cin>>p2;
	cin>>t2;
	if(p1==p2){
		cout<<1;
	    if(t1[0]==t2[0]&&t1[1]==t2[1]){
	    	cout<<1;
	    	if((t1[2]<='C'&&t2[2]<='C')||(t1[2]>'C'&&t2[2]>'C')){
		        cout<<1;
		        if((t1[2]=='A'&&t2[2]=='B')||(t1[2]=='B'&&t2[2]=='A')||(t1[2]=='B'&&t2[2]=='C')||(t1[2]=='C'&&t2[2]=='B')||(t1[2]=='E'&&t2[2]=='D')||(t1[2]=='E'&&t2[2]=='D')){
	                cout<<1;
	            }else cout<<"0";
            }else cout<<"00";
	    }else cout<<"000";
	}else cout<<"0000";
	return 0;
} 
