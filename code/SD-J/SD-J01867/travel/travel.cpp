#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
string a,b,c,d;
int s[105],g[105],z[105],x[105];
char f,k;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	for(int i=0;i<a.size();i++){
		s[i+1]=a[i]-'0';
	}
	for(int i=0;i<c.size();i++){
		g[i+1]=c[i]-'0';
	}
	for(int i=0;i<b.size();i++){
		if(b[i]>='A'&&b[i]<='Z'){
			f=b[i];
			continue;
		}
		z[i+1]=b[i]-'0';
	}
	for(int i=0;i<d.size();i++){
		if(d[i]>='A'&&d[i]<='Z'){
			k=d[i];
			continue;
		}
		x[i+1]=d[i]-'0';
	}
	for(int i=1;i<=2;i++){
		if(g[i]!=s[i]){
			cout<<"0000";
			return 0;
		}
	}
	cout<<"1";
	for(int i=1;i<=2;i++){
		if(x[i]!=z[i]){
			cout<<"000";
			return 0;
		}
	}
	cout<<"1";
	if((f>='A'&&f<='C'&&k>='A'&&k<='C')||(f>='D'&&f<='E'&&k>='D'&&k<='E')){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if(f>='D'&&f<='E'&&k>='D'&&k<='E'){
		cout<<"1";
		return 0;
	}else if(f>='A'&&f<='C'&&k>='A'&&k<='C'){
		if(f=='B'||k=='B'){
			cout<<"1";
			return 0;
		}else{
			cout<<"0";
			return 0;
		}
	}
	return 0;
} 
