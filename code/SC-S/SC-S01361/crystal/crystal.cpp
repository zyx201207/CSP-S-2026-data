#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,a[500005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	long long l=1,r=1,nowl=1,nows=0,ans=0;
	while(r<=n){
		if(nows<=m){
			ans=max(ans,nowl);
			nows+=nowl*(a[r+1]-a[r]);
			r++;nowl++;
		}
		else{
			nows-=a[r]-a[l];
			l++;nowl--;
		}
	}
	cout<<ans;
	return 0;
} 