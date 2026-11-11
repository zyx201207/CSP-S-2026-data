#include<bits/stdc++.h> 
using namespace std;
#define int long long
int n,m;
int a[500005];
int ans=-0x3f3f3f3f;
int f=1,f2=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1])f=0;
		if(i>=3){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
				f2=0;
			}
		}
	}
	if(f==1){
		cout<<n;
		return 0;
	}
	if(f2==1){
		sort(a+1,a+n+1);
		int ans=0;
		int i;
		for(i=n-1;i>=1;i--){
			if(m==ans){
				break;
			}if(m>ans){
				ans+=a[n]-a[i];
			}else{
				ans-=a[n]-a[i+1];
				i++;
				break;
			}
		}
		cout<<n-i;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		int j=i-1;
		int sum=m;
		while(a[i]-a[j]<=sum&&j>0)sum-=a[i]-a[j],j--;
		ans=max(ans,i-j);
	}
	cout<<ans;
	return 0;
}
