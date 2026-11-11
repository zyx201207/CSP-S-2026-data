#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[200005],ans=0,s,i;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+1+n);
	ans=a[1];
	if(m==n-1){
		for(int i=2;i<=n-1;i++){
			ans=ans^a[i];
		}
	}
	if(m==1){
		ans=a[n];
	}
	if(m==2){
		ans=a[n]^a[n-1];
	}
	if(m==n){
		for(int i=2;i<=n;i++){
			ans=ans^a[i];
		}
	}
	cout<<ans;
	return 0;
}