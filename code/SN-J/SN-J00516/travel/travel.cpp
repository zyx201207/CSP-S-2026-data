#include<bits/stdc++.h>
using namespace std;
string a , b , c , d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a[1]!=c[1]||a[0]!=c[0])cout<<0;
	else cout<<1;
	if((a[1]==c[1]&&a[0]==c[0])&&b[1]==d[1]&&b[0]==d[0])cout<<1;
	else cout<<0;
	if((a[1]==c[1]&&a[0]==c[0])&&b[1]==d[1]&&b[0]==d[0]){
		if(b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C'||b[2]>='D'&&b[2]<='F'&&d[2]>='D'&&d[2]<='F')cout<<1;
		else cout<<0;
	}else cout<<0;
	if(abs(b[2]-d[2])==1){
		if(b[2]>='C'&&b[2]<='D'&&d[2]>='C'&&d[2]<='D')cout<<0;
		else{
			if(a[1]!=c[1]||a[0]!=c[0])cout<<0;
			else{
				if(b[1]==d[1]&&b[0]==d[0])cout<<1;
				else cout<<0;
			}
		}
	}else cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
