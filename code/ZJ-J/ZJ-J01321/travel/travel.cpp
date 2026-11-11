#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int c1,c2,d1,d2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	for(int i=0;i<a.size();i++) c1=c1*10+a[i]-'0';
	for(int i=0;i<c.size();i++) c2=c2*10+c[i]-'0';
	if(c1!=c2){
		printf("0000");
		return 0;
	}
	printf("1");
	for(int i=0;i<b.size()-1;i++) d1=d1*10+b[i]-'0';
	for(int i=0;i<d.size()-1;i++) d2=d2*10+d[i]-'0';
	if(d1!=d2){
		printf("000");
		return 0;
	}
	printf("1");
	if(b[b.size()-1]<='C'&&d[d.size()-1]<='C'){
		if((b[b.size()-1]=='A'&&d[d.size()-1]=='C')||(b[b.size()-1]=='C'&&d[d.size()-1]=='A')){
			printf("10");
		}
		else{
			printf("11");
		}
	}
	else if(b[b.size()-1]>='D'&&d[d.size()-1]>='D'){
		printf("11");
	}
	else{
		printf("00");
	}
}
