#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],e=0; 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]|m){
			e=a[i]|m;
		}
	}
	cout<<e;
	return 0;
} 
