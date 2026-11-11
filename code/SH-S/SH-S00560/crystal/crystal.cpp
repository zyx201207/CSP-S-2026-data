#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],mn=0;
long long ans;
int main(){
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
	long long j=0,cnt=0,sum=0;
	for(int i=1;i<=n;i++){
		j=i;cnt=0;sum=0;
		for(;j>0;j--){
			sum+=a[i]-a[j];
			if(sum>m){
				break;
			}
			cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
} 
