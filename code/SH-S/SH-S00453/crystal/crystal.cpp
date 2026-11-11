#include<bits/stdc++.h>
using namespace std;

int n;
long long m;
long long a[500005];
long long sum;
int cnt,ans;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		sum=0;
		cnt=0;
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			sum+=abs(a[i]-a[j]);
			cnt++;
			if(sum>m){
				ans=max(ans,cnt);
			}
		}
	}
	
	cout<<ans;
	return 0;
}
