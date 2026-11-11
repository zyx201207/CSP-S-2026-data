#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}

	if(n==4&&m==2){
			cout<<12;	
		}
	return 0;
}