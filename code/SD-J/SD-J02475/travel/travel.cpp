#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a;
	char b;
	cin>>a>>b;
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else if(s1.a==s2.a&&c1==c2){
		cout<<1;
	}else if(s1.a==s2.a&&c1==c2&&s1.b==s2.b){
		cout<<1;
	}else if(s1.a==s2.a&&s1.b==s2.b&&c1==c2&&s1.b==s2.b+1||s1.b==s2.b-1){
		cout<<1;
	}else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
