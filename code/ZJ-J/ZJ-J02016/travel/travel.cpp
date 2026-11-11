#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}
string a,b,c,d;
string e;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		e+='1';
		if(b[0]==d[0]&&b[1]==d[1]){
			e+='1';
			if(b[2]>='D'&&b[2]<='F'&&d[2]>='D'&&d[2]<='F'){
				e+="11";
			}else{
				if(b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C'){
					e+='1';
					if(abs(b[2]-d[2])==1) e+='1';
					else e+='0';
				}else e+="00";
			}
		}else e="1000";
	} else e="0000";
	cout<<e;
	return 0;
}
