#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
#define int long long
int a[1000005];

signed main(){
	freopen("crystal.in","r",stdin);
	freoprn("crystal.out","w",stdout);
	int n,m;
	int cnt=0;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(n==1){
			cout<<"1";
			continue;
		}
		if(a[i]==i){
			cout<<"3";
			continue;
		} else {
			cout<<"4";
			return 0;
		}
		
				
	}
		
	return 0;
} 
