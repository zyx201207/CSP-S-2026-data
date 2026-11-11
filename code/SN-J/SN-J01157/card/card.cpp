#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
		
	int m,n;
	int a[100];
	cin>>m>>n; 
	for(int i=0;i<=m-1;i++){
		cin>>a[i];
	}
	
	cout<<m<<n;
	for(int i=0;i<=m-1;i++){
		cout<<a[i]<<" ";
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
