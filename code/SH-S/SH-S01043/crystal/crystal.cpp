#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m,a[500005],x[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		x[i]=a[i]-a[i-1];
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		int cnt=m,ans1=0;
			for(int j=i;j<=n;j++){
				if(cnt>=x[j]*(j-i+1)){
					cnt-=x[j]*(j-i+1);
					ans1++;
				}
				else break;
			}
		ans=max(ans,ans1+1);		
	}
	cout<<ans;
	return 0;
} 
