#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int a[500005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=n;i++){
		long long m1=0;
		int ans1=0;
		for(int j=1;j<i;j++){//基准值
			
			m1+=abs(a[j]-a[i]);
			if(m1>m)break;
			ans1++;
			if(ans1>=ans)ans=ans1;
			
		}
	}
	cout<<ans+1;
}






