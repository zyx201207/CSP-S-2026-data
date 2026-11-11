#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin>>n>>m;
	vector<long long> a(n),b(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	int ans=0;
	for(int i=1;i<=n;i++){
	long long s=0;
	int sum=1;
		for(int j=i;j<=n;j++){
			sum++;
		    if(m>s+(a[j]-a[j-1])*(sum-i)){
		    	ans=max(ans,sum);
		    	s+=(a[j]-a[j-1])*(sum-i);
			}else{
				continue;
			}
		}
	}
	cout<<ans;
	return 0;
} 
