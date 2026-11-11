#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n1,n2;
	int a1,a2;
	char a11,a22;
	cin>>n1>>a1>>a11>>n2>>a2>>a22;
	if(n1>=2||n1<=17||n1!=16){
		if(n1==n2){
			cout<<"1";
		}else{
			cout<<"0000";
			return 0;
		}
	}
	if(a1==a2){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if((a11=='C'&&a22=='D')||(a22=='C'&&a11=='D')){
		cout<<"0";
	}else{
		cout<<"1";
	}
	if(a11+1==a22&&a11==a22+1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
} 
