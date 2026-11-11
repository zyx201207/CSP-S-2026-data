#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d,e="";
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]&&a[1]==c[1]){
		e[0]=='1';
		if(b[0]==d[0]&&b[1]==d[1]){
			e[1]='1';
			int f=int(b[2])-int(d[2]);
			if(b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C'){
				e[2]='1';
				if(abs(f)==1){
					e="1111";
					cout<<e;
					return 0;
				}else{
					e="1110";
					cout<<e;
					return 0;
				}
			}else if(b[2]==d[2]||b[2]=='D'&&d[2]=='F'||b[2]=='F'&&d[2]=='D'){
				e="1111";
				cout<<e;
				return 0;
			}
			else{
				e="1100";
				cout<<e;
				return 0;
			}
		}
		else{
			e="1000";
			cout<<e;
			return 0;
		}
	}
	else{
		e="0000";
		cout<<e;
		return 0;
	}
	return 0;
}
