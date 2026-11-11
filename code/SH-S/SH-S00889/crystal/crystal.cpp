#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=1,r=2;
	int ans=1;
	long long cnt=0;
	while(r<=n){
		cnt+=(a[r]-a[r-1])*(r-l);
		while(cnt>m){
			cnt-=a[r]-a[l];
			l++;
		}
		ans=max(r-l+1,ans);
		r++; 
	}
	cout<<ans;
	return 0;
} 
