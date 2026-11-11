#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n;
	char a[1005];
	char b[1005];
	for(int i=1;i<=2;i++) {
		cin>>a[i]>>b[i];
		if(a[i]==b[i]){
			cout<<1;
			
		}
		else {
		for(int j=1;j<=4-i;j++){
			cout<<0;
		}
		break;
	}
	fclose(stdin);
	fclose(stdout);

	return 0;
	
}}
