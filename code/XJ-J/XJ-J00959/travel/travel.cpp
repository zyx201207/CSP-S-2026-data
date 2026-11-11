#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen{"travel.in","r",stdin);
	freopen{"travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s2>>c2>>s2;
	if(c1==c2){
		cout<<1111;
	}else{
		cout<<1110;
	}
	if(s1==s2){
		cout<<1100;
	}else{
		cout<<1000;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}