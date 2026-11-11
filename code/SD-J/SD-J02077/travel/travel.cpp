#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	char e[5]={'0','0','0','0','0'};
	if(a[0]==c[0]&&a[1]==c[1]){
		e[0]='1';
		if(b[0]==d[0]&&b[1]==d[1]){
			e[1]='1';
			if(((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C'))||((b[2]=='D'||b[2]=='F')&&(b[2]=='D'||b[2]=='F'))){
				e[2]='1';
				if(((b[2]=='A'||b[2]=='B')&&(d[2]=='A'||d[2]=='B'))||((b[2]=='C'||b[2]=='B')&&(d[2]=='C'||d[2]=='B'))||((b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='F'))){
					e[3]='1';
				}
			}
		}
	}
	for(int i=0;i<4;i++)
		cout<<e[i];
	return 0;
}
