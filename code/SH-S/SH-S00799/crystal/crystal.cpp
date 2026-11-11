#include<bits/stdc++.h>
using namespace std;
long long n,m,a[600000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long ans=0,l=0,r,t=0;
	for(int r=1;r<n;r++){
		t+=(a[r]-a[r-1])*(r-l);
		while(t>m){
			t-=a[r]-a[l];
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
