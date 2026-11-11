#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500010],b[500010];
int ans=-1,num=1;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>n>>m;
	if(n==1){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	for(int i=2;i<=n;i++){
		b[i]=b[i]*i+b[i-1];
	}
	for(int i=2;i<=n;i++){
		for(int j=num;j<=i;j++){
			if(b[i]-(a[i]-a[j])<=m){
				ans=max(ans,i-j);
			}
			else{
				num=j;
				continue;
			}
		}
	}
	cout<<ans+1;
	return 0;
} 
