#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000000],b[1000000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<n;++i)b[i]=a[i+1]-a[i];
	int l=0,r=1,lng=1,ans=0;
	long long cnt=0;
	while(r<=n){
		l++;
		ans=max(ans,lng);
		lng=r-l+1;
		m+=cnt;
		bool o=1;
		while(o){
			cnt=b[r];
			cnt*=lng;
			if(m>=cnt){
				m-=cnt;
				r++; 
				lng=r-l+1;
			}
			else o=0;
		}
		cnt=a[r]-a[l];
	}
	cout<<ans;
	return 0;
}
