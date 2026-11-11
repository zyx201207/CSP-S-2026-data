#include<bits/stdc++.h>
using namespace std ;
int main(){
	freopen("travel.in","r",stdin);
	freopen("traval.out","w",stdout);
	int flag1=0,flag2=0,flag3=0,flag4=0;
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		flag1=1;
	}
	if(b[0]==d[0]&&b[1]==d[1]){
		if(b[2]!=d[2]){
			flag2=1;
		}
	}
	if(b[2]<='C'&&d[2]<='C'){
		if(b[1]==d[1]){
			if(b[0]==d[0]){
				if(b[2]!=d[2]){
					flag3=1;
				}
			}
		}
	}
	else if(b[2]<='F'&&d[2]<='F'){
		if(b[1]==d[1]){
			if(b[0]==d[0]){
				if(b[2]!=d[2]){
					flag3=1;
				}
			}
		}
	}
	if(abs(b[2]-d[2])==1){
		if(b[1]==d[1]){
			if(b[0]==d[0]){
				flag4=1;
			}
		}
	}
	cout<<flag1<<flag2<<flag3<<flag4<<endl;
	return 0;
}
