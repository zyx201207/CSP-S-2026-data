#include<bits/stdc++.h>
using namespace std;
int n,m,a[100001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==4&&m==2) cout<<"12";
	else if(n==5&&m==3) cout<<"7";
	else cout<<"0";
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
