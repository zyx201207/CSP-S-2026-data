#include<bits/stdc++.h>
using namespace std;
char s[5],c[5],d[5];
string a,b;
bool o=1,a1,b1,c1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a;
	scanf("%s",c+1);
	cin >>b;
	scanf("%s",d+1);
	if(a==b){
		cout<<1;
	}
	else{
		cout<<"0000";return 0;
	}
	for(int i=1;i<=2;i++){
		if(c[i]!=d[i]){
			cout<<"000";o=0;return 0;
		}
	}
	if(o==1){
		cout<<1;
	}
	if((c[3]<='C'&&d[3]<='C')||(c[3]>'C'&&d[3]>'C')){
		cout<<1;
	}
	else{
		cout<<"00";return 0;
	}
	if(c[3]==d[3]-1||c[3]==d[3]+1){
		if((c[3]!='C'&&d[3]!='D')&&(c[3]!='D'&&d[3]!='C')){
			cout<<1;
		}
		else{
			cout<<"0";
		}
	}else{
		cout<<"0";
	}
}
