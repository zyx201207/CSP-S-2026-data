#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool flag1,flag2,flag3;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		flag1=1;
	}else{
		cout<<0;
	}
	if(flag1&&b[0]==d[0]&&b[1]==d[1]){
		cout<<1;
		flag2=1;
	}else{
		cout<<0;
	}
	if((b[2]<='C'&&d[2]<='C')||b[2]>='D'&&d[2]>='D'){
		if(flag1&&flag2){
		    cout<<1;
		    flag3=1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	if(flag1&&flag2&&flag3&&abs(b[2]-d[2])==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
