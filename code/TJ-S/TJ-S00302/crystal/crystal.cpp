#include <bits/stdc++.h>
using namespace std;
int a[500005];
int delt[500005];
long long num[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	int ans=0;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
 }
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		delt[i]=a[i]-a[i-1];
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			num[j]=(j-i)*delt[j]+num[j-1];		
			if(m==(num[j]-num[i]) && j==n){
				ans=max(ans,j-i+1);

				break;
			}
			else if((m>num[j]-num[i] && j==n) || m<(num[j]-num[i])){
				ans=max(ans,j-i);
				break;
			}
			
				 else continue;
		}
	}
	
	cout<<ans;
	return 0;
}

