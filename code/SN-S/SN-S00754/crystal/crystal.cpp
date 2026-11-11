#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum[500005],sumsum[500005],tot,ans=1,r,l,mid,s; 
int maxn,q;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++){
		sum[i]=a[1]-a[i];
		sumsum[i]=sumsum[i-1]+sum[i];
	}
	sumsum[0]=0;
	for(int i = 1;i <= n;i++){
		tot=q=0;
		for(int j=i-1;j>=l;j--){
			tot+=(a[i]-a[j]);
			q++;
			if(tot>m){
				l=j;
			}
		}
		maxn=max(maxn,q);
	}
	cout << maxn;
	return 0;
}
