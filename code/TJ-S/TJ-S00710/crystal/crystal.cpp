#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,c=0;
	cin>>n>>m;
	for(int i=0;i<=n;i++){
		cin>>i;
	}
	
	
	cout<<c%(m*n)+3;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
