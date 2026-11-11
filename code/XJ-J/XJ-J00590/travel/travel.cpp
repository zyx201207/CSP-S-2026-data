#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	int a,b,c,d;
	string c1,s1,c2,s2;
	cin>>c1>>c2>>s1>>s2;
	for(int i=1;i<4;i++){
		if(c1[i]==2 && s1[i]==2){
			a=1;
		}else{
			a=0;
		}
		if(c2[2]=='A' && s2[2]=='B'){
			b=1;
		}else{
			b=0;
		}
		if(c2[i]==1 && s2[i]==1){
			c=1;
		}else{
			c=0;
		}
		if(c2[i]!='F' || c2[i]!='D'){
			d=1;
		}else{
			d=0;
		}
	}
	cout<<a<<b<<c<<d;
	return 0;
}