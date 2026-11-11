#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long ans=0;
	vector<long long> a(n);
	for(int i=0;i<n;i++)
	cin>>a[i];
	vector<long long> cha(n-1);
	for(int j=0;j<=n-1;j++){
		
		if(j<n-1)
		cha[j]=a[j+1]-a[j];
		if(j==n-1)
		break;
		
	
		if(cha[j]*1+cha[j+1]*(j+1)<=m){
		
		m=m-cha[j]*1-cha[j+1]*(j+1);
		j=j+1;
		ans++;
		if(cha[j]=m){
		ans++;
}	}
	}
	
	cout<<ans<<'\n';
	
	return 0;
}
