#include<bits/stdc++.h>
using namespace std;
int n,ans=1;
long long m;
long long a[500005];
long long diff[500005],sum[500005];
bool check(int ll,int rr){
	long long tmp=0;
	for(int i=ll;i<=rr;i++){
		tmp+=a[rr]-a[i];
		if(tmp>m){
			return false;
		}
	}
	return tmp<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-ans+1;i++){
		int l=i-1,r=n+1;
		while(l+1<r){
			int mid=(l+r)/2;
			if(check(i,mid)){
				l=mid;
			}
			else{
				r=mid;
			}
		}
//		cout<<i<<" "<<l<<"\n";
		ans=max(ans,l-i+1);
	}
	cout<<ans;
	return 0;
} 
