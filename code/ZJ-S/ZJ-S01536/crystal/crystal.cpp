#include<bits/stdc++.h>
using namespace std;
int n,maxn=0;
long long m,a[500010],ans=0;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=1,r=0;
	while(r<n){
		r++;
		ans+=(a[r]-a[r-1])*(r-l);
		while(ans>m){
			ans-=a[r]-a[l];
			l++;
		}
		maxn=max(maxn,r-l+1);
	}
	cout<<maxn;
}
