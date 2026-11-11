#include<bits/stdc++.h>
using namespace std;
int n,m,x[500005];

int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<=n;i++){
		cin>>x[i];
	}
	sort(x,x+n);
	for(int i=0;i<=n;i++){
		cout<<x[i];
	}
	return 0;
} 
