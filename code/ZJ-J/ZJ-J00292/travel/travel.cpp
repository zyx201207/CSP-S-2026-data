#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		ans[0]=1;
		cout<<1;
	}
	else{
		ans[0]=0;
		cout<<0;
	}
	if(ans[0]==1&&b[0]==d[0]&&b[1]==d[1]){
		ans[1]=1;
		cout<<1;
	}
	else{
		ans[1]=0;
		cout<<0;
	}
	if(ans[0]==1&&ans[1]==1&&(('A'<=b[2]&&b[2]<='C'&&'A'<=d[2]&&d[2]<='C')||('D'<=b[2]&&b[2]<='F'&&'D'<=d[2]&&d[2]<='F'))){
		ans[2]=1;
		cout<<1;
	}
	else{
		ans[2]=0;
		cout<<0;
	}
	if(ans[1]==1&&(abs(int(b[2]-d[2]))==1||(b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D'))&&(('A'<=b[2]&&b[2]<='C'&&'A'<=d[2]&&d[2]<='C')||('D'<=b[2]&&b[2]<='F'&&'D'<=d[2]&&d[2]<='F'))){
		ans[3]=1;
		cout<<1;
	}
	else{
		ans[3]=0;
		cout<<0;
	}
	cout<<'\n';
	return 0;
}
