#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],bbb=50000001,ans=0; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i]==a[j]&&i!=j){
				ans++;
				if(a[i]+m/2==a[i+1]){
					ans++;
				}
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
