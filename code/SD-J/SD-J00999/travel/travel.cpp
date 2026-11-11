#include <bits/stdc++.h>
using namespace std;
int n,m;
string a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>a>>m>>b;
	if(n!=m){
		cout<<"0000";
	}else{
		cout<<"1";
		if(a[0]==b[0]&&a[1]==b[1]){
			cout<<"1";
			char x=a[2],y=b[2];
			if(x=='A'&&y=='B'||x=='B'&&y=='A'||x=='B'&&y=='C'||x=='C'&&y=='B'||x=='D'&&y=='F'||x=='F'&&y=='D'){
				cout<<"11";
			}else{
				if(x=='A'&&y=='C'||x=='C'&&y=='A'){
					cout<<"10";
				}else{
					cout<<"00";
				}
			}
		}else{
			cout<<"000";
		}
	}
	return 0;
}
