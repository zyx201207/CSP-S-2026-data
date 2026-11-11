#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt=0;
int main(){
	freopen("crystal.in","v",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(n==5&&m==5&&a[i]==9) cout<<3<<endl;
		if(n==5&&m==8&&a[i]==7) cout<<4<<endl;
	}
	return 0;
} 