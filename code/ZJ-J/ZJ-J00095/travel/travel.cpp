#include<bits/stdc++.h>
using namespace std;
int read(){
	char c=getchar();
	int s=0;
	while(c<'0' || c>'9'){
		c=getchar();
	}
	while(c>='0' && c<='9'){
		s=(s<<1)+(s<<3)+int(c-'0');
		c=getchar();
	}
	return s;
}
string a,b,c,d,e,f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
		e=b[0]+b[1];f=d[0]+d[1];
		if(e==f){
			cout<<"1";
			if(b[2]>='D' && d[2]>='D'){
				cout<<"11";
			}
			else if(b[2]<='C' && d[2]<='C'){
				cout<<"1";
				if(abs(int(b[2])-int(d[2]))==1){
					cout<<"1";
				}
				else{
					cout<<"0";
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