#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool ans[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	ans[1]=(a==c);
	ans[2]=(ans[1]&&b[0]==d[0]&&b[1]==d[1]);
	if(b[2]>='A'&&b[2]<='C'){
		if(d[2]>='A'&&d[2]<='C')ans[3]=ans[2];
	}else{
		if(d[2]>='D')ans[3]=ans[2];
	}
	if(abs((int)(b[2]-d[2]))==1)ans[4]=ans[3];
	for(int i=1;i<=4;i++)cout<<ans[i];
	return 0;
}
