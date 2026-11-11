#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
map<long long,long long>mp;
int main(){
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		mp[a[i]]++;
	}
	long long ans=0;
	for(long long i=1;i<=n;i++){
		ans=max(ans,mp[a[i]]);
	}
	sort(a+1,a+n+1);
	bool f=1;
	for(long long i=1;i<=n/2+1;i++){
		if(m<(a[n/2+1]-a[i])){
			f=0;break;
		}
		m-=(a[n/2+1]-a[i]);
		mp[a[i]]--;mp[a[n/2+1]]++;
		a[i]=a[n/2+1];
		ans=max(ans,mp[a[n/2+1]]);
	}
	long long k=n/2+1;
	if(f){
		while(m&&k<=n&&k+1<=n){
			if(m<k*(a[k+1]-a[k])){
				ans=max(ans,mp[a[k+1]]+m/(a[k+1]-a[k]));
				break;
			}
			else{
				m-=(k*(a[k+1]-a[k]));
				mp[a[k+1]]+=(k);
				mp[a[k]]-=(k);
				ans=max(ans,mp[a[k+1]]);
				k++;
			}
			//cout<<"\n"<<ans;
		}	
	}
	cout<<ans;
	return 0;
}