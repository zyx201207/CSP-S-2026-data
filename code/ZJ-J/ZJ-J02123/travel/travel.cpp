#include<bits/stdc++.h>
using namespace std;
int m,n,x,y;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a[0]=='0'){
		x=a[1]-48;
	}
	else{
		x=a[1]-38;
	}
	if(c[0]=='0'){
		y=c[1]-48;
	}
	else{
		y=c[1]-38;
	}
	if(b[0]=='0'){
		m=b[1]-48;
	}
	else{
		m=b[1]-38;
	}
	if(d[0]=='0'){
		n=d[1]-48;
	}
	else{
		n=d[1]-38;
	}
	if(x!=y){
		cout<<0<<0<<0<<0;
	}
	else{
		cout<<1;
		if(m!=n){
			cout<<0<<0<<0;
		}
		else{
			cout<<1;
			if(b[2]<'D'&&d[2]<'D'||b[2]>'C'&&d[2]>'C'){
				cout<<1;
				if(b[2]>'C'&&d[2]>'C'){
					cout<<1;
				}
				else if(b[2]=='B'||d[2]=='B'){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<0<<0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}