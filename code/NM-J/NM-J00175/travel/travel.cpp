#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	char m,n;
	string c,d;
	cin>>a>>c>>b>>d;
	if(a==b){                    
		if(c[0]==d[0]&&c[1]==d[1]){
			n=c[2];
			m=d[2];
			if(abs(int(n)-int(m))==1&&(max(n,m)=='F'||max(n,m)=='C'||max(n,m)=='B')){
				cout<<1111;
			}else if(abs(int(n)-int(m))==2&&(max(n,m)=='C')){
				cout<<1110;
			}else{
				cout<<1100;
			}
		}else{
			cout<<1000;
		}
	}else{
		cout<<"0000";
	}
	
	return 0; 
} 

