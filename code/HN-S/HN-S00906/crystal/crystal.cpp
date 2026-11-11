#include<bits/stdc++.h>
using namespace std;
int a[500000];
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==0){
		int cnt=1;
		for(int i=1;i<n;i++){
				if(a[i]==a[i+1]){
					cnt++;
				}	
			}
		cout<<cnt;
		return 0;
	}
	if(n==1){
		cout<<n;
		return 0;
	}
	int ent=0;
	for(int i=1;i<n;i++){
		ent+=i;
	}
	if(m>=ent*(a[n]-a[n-1])){
		cout<<n;
	}else{
		for(int i=1;i<=n;i++){
			ent=0;
			for(int j=1;j<n-i;j++){
				ent+=i;
			}
			if(m>=ent*(a[n]-a[n-1])){
				cout<<n-i;
				return 0;
			}
		}
	}
	return 0;
}
