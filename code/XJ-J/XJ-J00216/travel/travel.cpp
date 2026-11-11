#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,t,a[100],b[100];
	cin>>n>>t;
	for(int i=1;i<=n;i++){	
		if(a[n]!=01||a[n]!=17&&b[n]!=01||b[n]!=17){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}
	for(int i=1;i<=n;i++){
		if(a[t]=b[t]){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}
	return 0;
} 
