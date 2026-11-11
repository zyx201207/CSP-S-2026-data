#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int ans,sum,a,b;
	if(c1==c2){
		ans=1;
	}else{
		ans=0;
	}
	if(s1=='s2'-1||s2=='s1'-1){
		sum=1;
		a=1;
	}else{
		sum=0;
		a=0;
	}
	if('s1'<='c'&&'s2'<='c'||'s1'<='F'&& 's1'>='D'&&'s2'<='F'&&'s2'>='D'){
		b=1;
	}else {
		b=0;
	}
	cout<<ans<<sum<<b<<a;
	return 0;
}
