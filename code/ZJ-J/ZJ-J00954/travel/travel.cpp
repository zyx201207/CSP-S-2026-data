#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a,b,c,d;
	char e,f,g;
	cin>>a>>b>>e>>c>>d>>f;
	if(a==c){
		cout<<1;
		if(b==d){
			cout<<1;
			if(e=='A'||e=='B'||e=='C'&&f=='A'||f=='B'||f=='C'){
				cout<<1;
				if(e+f!='A'+'C'){
					cout<<1;
				}else{
					cout<<0;
				}
			}else if(e=='D'||e=='F'&&f=='D'||f=='F'){
				cout<<11;
				return 0;
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
}