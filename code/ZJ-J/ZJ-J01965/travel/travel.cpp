#include<bits/stdc++.h>
using namespace std;
int m,n;
char a,b,c,d,e,f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>m>>a>>b>>c>>n>>d>>e>>f;
	if(m==n){
		cout<<1;
		if(a==d and b==e){
			cout<<1;
			if(c=='F' and f=='D' or c=='D' and f=='F'){
				cout<<11;
			}
			else if(c=='A' and f=='B' or c=='B' and f=='C' or c=='C' and f=='B' or c=='B' and f=='C'){
				cout<<11;
			}
			else if(c=='A' and f=='C' or c=='C' and f=='A'){
				cout<<10;
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}