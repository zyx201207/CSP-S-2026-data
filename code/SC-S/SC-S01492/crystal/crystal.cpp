#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
    cin>>n>>m;
	vector<long long> a(n);
	for(int i=0;i<n;++i) cin>>a[i];
	sort(a.begin(),a.end());
	int l=0,ans=0;
	long long sum=0;
	for(int i=0;i<n;++i){
		sum+=a[i];
		while(a[i]*(i-l+1)-sum>m){
			sum-=a[l];
			l++;
		}
		ans=max(ans,i-l+1);
	}
    cout<<ans;
	return 0;
}