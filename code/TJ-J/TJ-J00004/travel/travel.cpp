#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;
	char a[4],b[4];
	cin>>n>>a>>m>>b;
	if(n!=m){cout<<"0000";return 0;}
	else cout<<"1";
	int x=a[0]*10+a[1],y=b[0]*10+b[1];
	if(x==y){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	char q=a[2],w=b[2];
	if((q<='C'&&w<='C')||(q>'C'&&w>'C')) cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	if(abs(q-w)==1) cout<<"1";
	else cout<<"0";
	fclose(stdin);
	fclose(stdout);
}
