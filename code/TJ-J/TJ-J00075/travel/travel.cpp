#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,s1,c2,s2;
	char a1,a2;
	cin>>c1>>s1>>a1>>c2>>s2>>a2;
	if(c1!=c2){
		cout<<"0000";
	}else if(s1!=s2){
		cout<<"1000";
	}else{
		if(a1<a2){
			char n=a1;
			a1=a2;
			a2=n;
		}
		if(a1=='F'&&a2=='D'){
			cout<<"1111";
		}else if(a1=='F'||a1=='D'){
			cout<<"1100";
		}else if(a1-1==a2){
			cout<<"1111";
		}else{
			cout<<"1110";
		}
	}
	return 0;
}
