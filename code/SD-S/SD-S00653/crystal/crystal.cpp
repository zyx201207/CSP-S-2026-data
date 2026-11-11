#include <bits/stdc++.h>
using namespace std;
long long n,m,sum,sum1,ans;
long long a[10000005];
bool flag;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		sum+=(a[n]-a[i]);
	}
	if(sum<=m){
		cout<<n;
	}
	for(int i=2;i<n;i++){
		if(a[i]-a[i-1]==a[i+1]-a[i]){
			flag=1;
		}
		else{
			flag=0;

			break;
		}
	}
	if(flag==1){
		int cnt=a[2]-a[1];
		for(int i=1;i<n;i++){
			int q=cnt;
			if(m>=cnt){
				cnt+=cnt+1;
			}
			else{
				cout<<i;
				break;
			}
		}
				
	}else{
		for(int i=1;i<=n;i++){
			sum1=0;
			for(int j=1;j<i;j++){
				sum1+=(a[i]-a[j]);
			}
			if(sum1==m){		
				ans=i;
			}
		}
		cout<<ans;
	}
	return 0;
}
