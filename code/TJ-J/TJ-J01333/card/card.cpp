#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<n;
	for(int i=1;i<=m-1;i++){
		cout<<m-i+1<<' ';
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
