#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=0,k=1000000000005,e=1;
int main(){
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==0){
		cout<<0;
	}
	else{
			for(int i=1;i<=n;i++){
				if(a[i+1]-a[i]<=k){
				 		k=a[i+1]-a[i]; 
				}
				m-=k*i;
				for(int j=1;j<=i;j++){
					a[j]+=k;
				}
				if(m==0){
					break;
				}
				k=10000000000000005;
			}
			for(int i=1;i<=n;i++){
				if(a[i]==a[i+1]){
					ans++;
				}
			}
			cout<<ans+1;
	}
	return 0;
} 
