#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],js=0;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ls=a[2]-a[1];
	for(int i=1,j=0;i<=n;i++,j+=(i-1)*ls){
		if(m-j>=0)js++;
		else break;
	}
	cout<<js;
	return 0;
} 
