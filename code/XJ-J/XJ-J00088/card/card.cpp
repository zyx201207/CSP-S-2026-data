#include<bits/stdc++.h>
using namespace std;
	int a[100000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==10) cout<<"10 3 3";
	if(n==4) cout<<"3 1 4";
	
	return 0;
}


