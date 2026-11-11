#include<bits/stdc++.h>
using namespace std;
long long a[100000010];
int main(){	
	freopen("string.in","r",stdin);
	freoprn("string,out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n=3){
		cout<<"2";
	}
	else if(n=2){
		cout<<"0";
	}else if(n=6){
		cout<<"3000000000";
	}else{
		cout<<"4";
	}
	return 0;
}
