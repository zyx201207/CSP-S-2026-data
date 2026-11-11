#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,x;
string m,y;
bool t,c;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m>>x>>y;
	t=m[0]-'0'==y[0]-'0'&&m[1]-'0'==y[1]-'0';
	c=m[2]<='C'&&m[2]>='A'&&y[2]<='C'&&y[2]>='A'||m[2]<='E'&&m[2]>='D'&&y[2]<='E'&&y[2]>='D';
	if(x==n){
		cout<<1;
	}else{
		cout<<0;
	}if(x==n&&t){
		cout<<1;
	}else{
		cout<<0;
	}if(x==n&&t&&c){
		cout<<1;
	}else{
		cout<<0;
	}if(x==m[0]==y[0]&&m[1]==y[1]&&c&&abs(m[2]-y[2])==1){
		cout<<1;
	}else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

