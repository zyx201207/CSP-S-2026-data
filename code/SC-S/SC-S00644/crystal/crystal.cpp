#include <bits/stdc++.h>
using namespace std;
const int N=500005;
int n;
long long m;
long long a[N];
long long q[N<<1];
long long l,r;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	long long sum=0,ans=0;
	q[++r]=a[1];
	for(int i=2;i<=n;i++){
		while(sum+(a[i]-q[r])*(r-l)>m&&l<r){
			sum-=a[r]-a[l+1];
			l++;
		}
		sum+=(a[i]-q[r])*(r-l);
		q[++r]=a[i];
		ans=max(ans,r-l);
	}
	cout<<ans;
	return 0;
} 