#include<bits/stdc++.h>
using namespace std;
string a,b,c,d; 
int n,m;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		if(b[0]==0){
			n=b[1]-'0';
		}else{
			n=10+b[1]-'0';
		}
		if(d[0]==0){
			n=d[1]-'0';
		}else{
			m=10+d[1]-'0';
		}
		if(n==m){
			cout<<1;
			n=int(b[2])-'A'+1;
			m=int(d[2])-'A'+1;
			if((n<=3&&m<=3)||(n>=4&&m>=4)){
				cout<<1;
				if(max(m,n)-min(m,n)==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0<<0;
			}
		}else{
			cout<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
	return 0;
} 
