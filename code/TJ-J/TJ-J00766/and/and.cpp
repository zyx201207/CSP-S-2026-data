#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r"stdin);
	freopen("travel.out","w"stdout);
	int a,n,m,b;
	cin<<n,m;
	for(int i=0;i=n;i++){
		cin>>a[i];
	}
	if(m=n){
		cout<<n; 
	}else{
		cout<<m;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
