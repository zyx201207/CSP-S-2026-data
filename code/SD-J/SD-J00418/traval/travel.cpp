#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int c1,c2,a,b,f,g;
    string s1[3],s2[3],d,e;
	cin>>c1>>s1[10000]>>c2>>s2[10000];
	a=3;
	b=3;
	if(c1==c2){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	for(int i=0;i<a;i++){
		if(s1[i]>"0"&&s1[i]<"17"){
			d=s1[i];
		}
	}
	for(int i=0;i<b;i++){
		if(s2[i]>"0"&&s2[i]<"17"){
			e=s2[i];
		}
	}
	if(d==e){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	cout<<0;
	cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
