#include<bits/stdc++.h>
using namespace std;
int c1,s1,a,c2,s2,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	cin>>a>>b;
	if(c1==c2)
		cout<<"1";
	else{
		cout<<"0000";
	}
	if(a==b){
		cout<<"1";
	}
	else{
		cout<<"0";	
	}
	if(s1==s2){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if((s1-s2==1)||(s2-s1==1)){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

