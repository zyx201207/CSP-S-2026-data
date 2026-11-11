#include <bits/stdc++.b>
using namespace std;
int main(){
	freopen("travel.in","r",stdin)
	freopen("travel.out","w",stdout)
	int c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}
	for(int i=1;i<=4;i++){
		if(c1=c2){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
		if(s1%10=s2%10){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	    if(s1=s2){
	    	cout<<"1";
		}
		else{
			cout<<"0";
		}
		cout<<"1";
	}
	return 0;
}

