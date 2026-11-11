#include<bits/stdc++.h>
using namespace std;
int n,dp[5005][5005],ans,f;
unsigned long long m;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2])f=1;
	}
	if(f){
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			int len=1;
			unsigned long long m1=m;
			for(int j=i;j<=n;j++){
				if(j<n){
					long long c=a[j+1]-a[j];
					if(len*c<=m1){
						m1-=len*c;
						len++;
					}else{
						ans=max(ans,len);
						break;
					}
				}else ans=max(ans,j-i+1);
			}
		}
		cout<<ans;
	}else{
		long long c=abs(a[2]-a[1]);
		int len=1;
		while(m>=len*c){
			m-=len*c;
			len++;
		}
		cout<<len;
	}
	return 0;
}