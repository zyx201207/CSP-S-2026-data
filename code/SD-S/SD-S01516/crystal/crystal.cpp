#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500050],b[500050];
long long sum[500050];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long ans=0;
	for(int i=1;i<=n;i++){
		long long cnt=0;
		long long czc=0;
		for(int j=i;j>=0;j--){
			if(cnt>m){
				czc=j;
				break;
			}
			cnt+=(a[i]-a[j]);
		}
		long long op=i-czc;
		ans=max(op,ans);
	}
	cout<<ans;
	return 0;
}
