#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool fa,fb,fc,fd;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		fa=1;
		if(b[0]==d[0]&&b[1]==d[1]){
			fb=1;
			if(b[2]<='C'&&d[2]<='C'){
				fc=1;
				if((char)(b[2]+1)==d[2]||(char)(b[2]-1)==d[2])fd=1;
			}
			if(b[2]=='D'&&d[2]=='F'||b[2]=='F'&&d[2]=='D')fc=fd=1;
		}
	}
	cout<<fa<<fb<<fc<<fd;
	return 0;
}