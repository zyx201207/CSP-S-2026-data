#include<bits/stdc++.h>
using namespace std;

const int N=5e5;
long long n,m,a[N+5],s[N+5];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	long long j=1;
	long long ans=0;
	for(int i=1;i<=n;i++){
		while(j<n){
			if((j+1-i+1)*a[j+1]-(s[j+1]-s[i-1])<=m){
				j++;
			}
			else break;
		}
		ans=max(ans,j-i+1);
	}
	cout<<ans<<endl;
	return 0;
}
