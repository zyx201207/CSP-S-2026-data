#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN=500005;
ll n,m,a[MAXN],sum,ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	//cout<<n<<"\n";
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//for(int i=1;i<=n;i++) cout<<a[i]<<"\n";
	sort(a+1,a+n+1);
	ll l=1,r=0,sum=0;
	while(1){
		r++;
		sum+=a[r];
		//cout<<"l: "<<l<<" r: "<<r<<" sum: "<<sum<<" mm: "<<abs(a[r]*(r-l+1)-sum)<<"\n";
		while(abs(a[r]*(r-l+1)-sum)>m){
			sum-=a[l];
			l++;
		}
		//cout<<"l: "<<l<<" r: "<<r<<" sum: "<<sum<<" mm: "<<abs(a[r]*(r-l+1)-sum)<<"\n";
		ans=max(ans,r-l+1);
		if(r>=n){
			break;
		}
	}
	cout<<ans;
	return 0;
}