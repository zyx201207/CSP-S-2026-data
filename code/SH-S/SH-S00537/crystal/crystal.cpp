#include<bits/stdc++.h>
#define int long long
using namespace std;
long long a[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int m1=m;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(i!=2 && i!=1 && a[i]-a[i-1]!=a[i-1]-a[i-2]) flag=false;
	}
	if(flag==true){
		int c=a[2]-a[1];
		int x=(-1+sqrt(1+8*m/c))/2+1;
		cout<<min(x,n);
		return 0;
	}
	int ans=0;
	for(int i=2;i<=n;i++){
		m1=m;
		int sum=1;
		for(int j=i-1;j>=1;j--){
			m1-=(a[i]-a[j]);
			if(m1<0) break ;
			sum++;
		}
		ans=max(ans,sum);
	}
	cout<<ans<<endl;
	return 0;
} 
