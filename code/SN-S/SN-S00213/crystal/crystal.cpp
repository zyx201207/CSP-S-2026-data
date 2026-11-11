#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[500005]={},a1[500005]={};
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		a1[i]=a[i];
	}
	sort(a+1,a+n+1);
	sort(a1+1,a1+n+1);
	long long cnt[500005]={};
	cnt[0]=1;
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=m;j++){
			if(a1[i]<a1[i+1]){
				a1[i]++;
				cnt[i]++;
			}
		}
		for(long long j=1;j<=n;j++){
			a1[i]=a[i];
		}
	}
	sort(cnt+1,cnt+n+1);
	cout<<cnt[n-1];
	return 0;
}
