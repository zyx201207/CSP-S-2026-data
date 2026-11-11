#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,ans;
int f=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin>>a>>b>>c>>d;
	if(a==c){
		ans+='1';
	}else ans+='0';
	if(b[0]==d[0]&&b[1]==d[1]&&ans[0]=='1'){
		ans+='1';
	}else {
	ans+='0';
	}
	if((('A'<=b[2]&&b[2]<='C'&&'A'<=d[2]&&d[2]<='C')||('D'<=b[2]&&b[2]<='F'&&'D'<=d[2]&&d[2]<='F'))&&ans[1]=='1'){
		ans+='1';
	}else ans+='0';
	if(b[2]+1==d[2]||d[2]+1==b[2]){
		f=1;
	}
	if(ans[0]=='1'&&ans[1]=='1'&&ans[2]=='1'&&f){
		ans+='1';
	}else ans+='0';
	cout<<ans;
	return 0;
} 
