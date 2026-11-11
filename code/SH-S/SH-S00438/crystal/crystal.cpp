#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+5;
int n,ans=-1;
ll m,a[maxn],c[maxn],sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	sum=0;
	if(n<=5000){
		for(int j=1;j<=n;j++){
			sum=0;
			for(int i=j;i<=n;i++){
				c[i]=a[i]-a[i-1];
				sum+=c[i]*(i-1);
				if(sum>m){
					ans=max(ans,i-j);
					i=n+1;
				}
			}
		}
		if(ans!=-1)
			cout<<ans;
		else
			cout<<n;
		return 0;
	}
	else{
		for(int i=1;i<=n;i++){
			c[i]=a[i]-a[i-1];
			sum+=c[i]*(i-1);
			if(sum>m){
				cout<<i-1;
				return 0;
			}
		}
		cout<<n;
	}
	return 0;
}
