#include<bits/stdc++.h>
using namespace std;
int a[100000+5];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxx=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[i]=x;
	}
	return 0;
} 
