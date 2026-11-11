#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int a[4]={};
	if(c1[1]==c2[1]&&c1[2]==c2[2]&&c1[2]!='1'&&c1[1]!='1'&&c1[2]!='6'&&c2[1]!='1'&&c2[2]!='1'&&c2[2]!='6'){
		a[1]=1;
		cout<<a[1];
	}
	if(s1[1]=s2[1]&&s1[1]<'2'&&s2[1]<'2'){
		a[2]=1;
		cout<<a[2];
	}
	if(s1[2]=s2[2]){
		a[3]=1;
		cout<<a[3];
	}
	if(s1[3]-'A'==s2[3]-'A'){
		a[4]=1;
		cout<<a[4];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
