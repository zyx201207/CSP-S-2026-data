#include<bits/stdc++.h>

using namespace std;
string b,d;
long long a,c,e;
int main(){
	freopen(travel.in,"r",stdin);
	freopen(travel.out,"w",stdout);
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<0<<0<<0<<0;
		return 0; 
	}
	else{
		cout<<1;
		if(b[0]==d[0]){
			if(b[1]==d[1]){
				cout<<1;
				if(b[2]=='F'||b[2]=='D'){
					e=1;
				}
				if(e==1){
					if(d[2]=='D'||d[2]=='F'){
						cout<<1;
						e=2;
					}
					else{
						cout<<0<<0;
						return 0;
					}
				}
				else{
					if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
						cout<<1;
						e=3;
					}
					else{
						cout<<0<<0;
						return 0;
					}
				}
			}
			else{
				cout<<0<<0<<0; 
				return 0;
			}
		}
		else{
			cout<<0<<0<<0; 
			return 0;
		}
	}
	if(e==2){
		cout<<1;
		return 0;
	}
	else{
		if(b[2]=='B'||d[2]=='B'){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
