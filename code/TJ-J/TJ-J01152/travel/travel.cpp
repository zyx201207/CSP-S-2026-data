#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w,stdout);
	int a,b;
	string c,d;
	int aa=0,bb=0,cc=0,dd=0;
	cin>>a>>c>>b>>d;
	if(a==b){
		aa=1;
		int num1=(c[0]-'0')*10+(c[1]-'0');
		int num2=(d[0]-'0')*10+(d[1]-'0');
		if(num1==num2){
			bb=1;
			if(((c[2]>='A' && c[2]<='C') && (d[2]>='A' && d[2]<='C')) || ((c[2]>='D' && c[2]<='F') && (d[2]>='D' && d[2]<='F'))){
				cc=1;
				if((c[2]-d[2]==1 || d[2]-c[2]==1) || ((c[2]=='D') && (d[2]=='F')) || ((c[2]=='F') && (d[2]=='D'))){
					dd=1;
				}
			}
		}
	}
	cout<<aa<<bb<<cc<<dd;
	return 0;
}
