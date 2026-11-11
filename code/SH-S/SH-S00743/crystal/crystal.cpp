#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+9;
int n,m;
long long a[MAXN];
int ans=0;
int l=0,r=0;
int sm=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 0;i < n;i ++)cin>>a[i];
	sort(a,a+n);
	while(r<n){
		while(sm>m){
			sm-=a[r]-a[l];
			l++;
		}
		ans=max(ans,r-l+1);
		sm+=(a[r+1]-a[r])*(r-l+1);
		r++;
	}
	cout<<ans;
	return 0;
} 
