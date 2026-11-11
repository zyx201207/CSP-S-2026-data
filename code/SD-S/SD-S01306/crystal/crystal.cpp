#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500006],l=1,r=1,ans,d[500006];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) d[i]=d[i-1]+a[i];
	while(r<=n){
		if(m>=a[r]*(r-l+1)-(d[r]-d[l-1])){
			ans=r-l+1;
		}else{
			l++;
		}
		r++;
	}
	cout<<ans;
	
	return 0;
} 
