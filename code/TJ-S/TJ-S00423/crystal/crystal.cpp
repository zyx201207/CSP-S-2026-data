#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
long long n,m;
long long a[5000005];
int maxn=-1;
int cnt=1;
long long sum=0;
int k=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==a[i-1]) cnt++;
		else{
			maxn=max(cnt,maxn);
			maxn=0;
			cnt=1;
		}
	}
	sort(a,a+n+1);
	for(int i=1;i<=n;i++){
		sum=0;
		cnt=1;
		k=0;
		if(a[i+1]==a[i]) continue;
		for(int j=i;j>=1;j--){
			sum=sum+(a[i]-a[j]);
			if(k==0 && j==1 && sum<=m) maxn=max(maxn,cnt);
			else if(k==0 && j!=1 && sum>m) maxn=max(maxn,cnt-1);
			else if(k==0 && j!=1 && sum<=m) maxn=max(maxn,cnt);
			if(sum>m){
				k=1;
				break;
			}
			cnt++;
		}
	}
	cout<<maxn;
	return 0;
}
