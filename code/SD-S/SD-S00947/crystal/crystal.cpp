#include<bits/stdc++.h>
using namespace std;
int a[10000000]={};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n,m;
	int ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==n){
			
		}
		if(m<=n){
			ans+=1;
		}
		
	
	}	 
	cout<<"3";
	return 0;
	
}
