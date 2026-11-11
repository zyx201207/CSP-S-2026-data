//SN-J00767 汤佳忆 西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
int cr,cx,sr,sx;
string a,b,c,d,da;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	for(int i=0;i<(int)a.size();++i){
		cr*=10;cx*=10;sr*=10;sx*=10;
		cr+=(a[i]-'0');cx+=(c[i]-'0');sr+=(b[i]-'0');sx+=(d[i]-'0');
	}
	//cout<<cr<<sr<<cx<<sx;
	if(cx==cr){
		da+='1';
		if(sr==sx){
			da+='1';
			if((b[2]<='C'&&d[2]<='C')||(b[2]>'C'&&d[2]>'C')){
				da+='1';
				int x=b[2]-'A',y=d[2]-'A';
				if(abs(x-y)==1)da+='1';
				else da+='0';
			}
			else da+="00";
		}
		else da+="000";
	}else da+="0000";
	cout<<da;
	return 0;
}
