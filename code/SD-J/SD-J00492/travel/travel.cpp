#include<bits/stdc++.h>
using namespace std;
int a,b,p,q;
char x[6],y[3];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>a>>x>>b>>y;
	p=(x[0]-'0')*10+x[1]-'0';
	q=(y[0]-'0')*10+y[1]-'0';
	if(a==b){
		cout<<1;
		if(p==q){
			cout<<1;
			if(x[2]=='A'){
				if(y[2]=='B'||y[2]=='C'){
					cout<<1;
					if(y[2]=='B')
						cout<<1;
					else
						cout<<0;
				}else
					cout<<0<<0;
			}else if(x[2]=='B'){
				if(y[2]=='A'||y[2]=='C'){
					cout<<11;
				}else
					cout<<0<<0;
			}else if(x[2]=='C'){
				if(y[2]=='A'||y[2]=='B'){
					cout<<1;
					if(y[2]=='B')
						cout<<1;
					else
						cout<<0;
				}else
					cout<<0<<0;
			}else if(x[2]=='D'){
				if(y[2]=='F')
					cout<<11;
				else
					cout<<0<<0;
			}else if(x[2]=='F'){
				if(y[2]=='D')
					cout<<11;
				else
					cout<<0<<0;
			}
		}
		else
			cout<<0<<0<<0;
	}else
		cout<<0<<0<<0<<0;
}
