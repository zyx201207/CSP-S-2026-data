#include<bits/stdc++.h>
using namespace std;
	int n;
	int a[500001],m,ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		if(a[i]==a[i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
