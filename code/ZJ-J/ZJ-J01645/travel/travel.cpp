#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,ans="0000";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<ans;
		return 0;
	}
	ans[0]='1';
	int x=(b[0]-'0')*10+b[1]-'0';
	int y=(d[0]-'0')*10+d[1]-'0';
	if(x!=y){
		cout<<ans;
		return 0;
	}
	ans[1]='1';
	int s1=b[2]-'A',s2=d[2]-'A';
	if((s1<=2&&s2<=2)||(s1>2&&s2>2)){
		ans[2]='1';
		if(abs(s1-s2)==1){
			printf("1111");
			return 0;
		}
		cout<<ans;
		return 0;
	}else{
		cout<<ans;
		return 0;
	}
	return 0;
}