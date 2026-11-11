#include<bits/stdc++.h>
using namespace std;
string a,b,x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>x>>y;
	if(a==x){
		cout<<1;
		if(b[0]==y[0]&&b[1]==y[1]){
			cout<<1;
			char n=b[2];
			char m=y[2];
			if(('A'<=n&&n<='C'&&'A'<=m&&m<='C')||('D'<=n&&n<='F'&&'D'<=m&&m<='F')){
				cout<<1;
				if(n=='A'&&m=='B'||n=='B'&&m=='A'||n=='B'&&m=='C'||n=='C'&&m=='B'||n=='D'&&m=='F'||n=='F'&&m=='D'){
					cout<<1;
				}
				else{
					cout<<0;
				}
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
