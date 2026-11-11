#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200009];
long long vis[200009];
long long ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=n;i>n-m;i--){
		vis[i]=a[i];
	}
	ans=vis[n];
	for(int i=n;i>n-m;i--){
		ans=ans&vis[i];
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;	
}