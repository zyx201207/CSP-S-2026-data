#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,s1;
	char c2,s2;
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1){
		if(s2-c2==1){
			cout<<"0000";
	    }else if(s2-c2!=1){
	    	cout<<"1100";
		}else{
			cout<<"1000";
		}
	}else{
		cout<<"1111";
	}

	return 0;
}
