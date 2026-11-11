#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+10];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=3;j<=n;j++){
			if((a[i]-a[i-1])+(a[i]-a[i-2])==m){
				cout<<a[i];
			}
		}
	}
	
	return 0;
} 


















 
