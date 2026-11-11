#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n-1;i++){
		if(a[i]==a[i+1])continue;
		if(m<i*(a[i+1]-a[i])){
			ans=i+1;
			break;
		}
		m-=i*(a[i+1]-a[i]);
		a[i]=a[i+1];
	} 
	cout<<ans;
	return 0;
} 

 