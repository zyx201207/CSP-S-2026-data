#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	char c1,s1,c2,s2;
	int a=0,b=0,c=0,d=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a=1;
		cout<<a;
	}else{
		cout<<a<<b<<c<<d;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(s1==s2+1||s1==s2-1||s1==s2+2||s1==s2-2){
		b=1;
		cout<<b;
	}else{
		cout<<b<<c<<d;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if((s1==s2+1||s1==s2-1)&&!(s1==s2+2||s1==s2-2)){
		c=1;
		cout<<1;
	}else{
		cout<<c<<d;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(s1==s2+1||s1==s2-1){
		d=1;
		cout<<d;
	}else{
		cout<<d;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
