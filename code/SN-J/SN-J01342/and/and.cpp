#include<bits/stdc++.h>
using namespace std;

int n,m,a,s;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		s=max(s,s^a);
	}
	
	cout<<s;
	
	return 0;
} 
