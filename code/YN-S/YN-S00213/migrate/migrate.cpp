#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	int n,d;
	string x;
	int ans=0;
	cin>>c>>t;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=1;i<=n;i++){
		if(x[i+1]-x[i]<=d){
			ans++;
		}else ans=0;
	}
	cout<<ans;
	return 0;
}