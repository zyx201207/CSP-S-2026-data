#include<bits/stdc++.h>
using namespace std;
long long a[500010],b[500010],c[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	bool ff=true,fff=true;
	long long n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]!=i)ff=false;
		b[i]=a[i]-a[i-1];
		c[i]=(i-1)*b[i]+c[i-1];
	}
	if(ff==true){
		int sum=1;
		for(int i=1;i<=n;i++){
			if(m-i>=0){
				sum++;m-=i;
			}
		}
		cout<<sum;
		return 0;
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		long long sum=0;
		for(int j=n;j>=i;j--){
			if(double(c[j]-c[i])-(i-1)*(a[j]-a[i])>m)sum++;
			else break;
		}
		ans=max(ans,(n-sum-i+1));
	}
	cout<<ans;
	return 0;
} 
