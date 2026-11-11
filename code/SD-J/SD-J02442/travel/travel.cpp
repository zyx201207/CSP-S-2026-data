#include<bits/stdc++.h>
using namespace std;
string a,b;
string n,m;
int z(string n){
	int shi=n[0]-'0';
	int ge=n[1]-'0';
	return shi*10+ge;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>a>>m>>b;
	if(z(n)==z(m)){
		cout<<1;
		if(z(a)==z(b)){
			cout<<1;
			if(a[2]=='A'){
				if(b[2]=='B'){
					cout<<"11";
				}
				else if(b[2]=='C'){
					cout<<"10";
				}
				else cout<<"00";
			}
			if(a[2]=='B'){
				if(b[2]=='A'){
					cout<<"11";
				}
				else if(b[2]=='C'){
					cout<<"11";
				}
				else cout<<"00";
			}
			if(a[2]=='C'){
				if(b[2]=='B'){
					cout<<"11";
				}
				else if(b[2]=='A'){
					cout<<"10";
				}
				else cout<<"00";
			}
			if(a[2]=='D'){
				if(b[2]=='F'){
					cout<<"11";
				}
				else cout<<"00";
			}
			if(a[2]=='F'){
				if(b[2]=='D'){
					cout<<"11";
				}
				else cout<<"00";
			}
		}
		else cout<<"000";
	}
	else{
		cout<<"0000";
	}
	return 0;
} 
