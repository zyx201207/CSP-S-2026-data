#include<bits/stdc++.h>
using namespace std;
int a[10002];
int d,n;
int  ans(int x){
	int num;
	if(x+d==a[n]){
		num++;
	}
	return num;
} 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<ans(a[0]);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
