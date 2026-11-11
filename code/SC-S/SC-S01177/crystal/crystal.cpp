#include<bits/stdc++.h>
using namespace std;
long long n,m,s[500005],ans=-1;
long long check(long long x){
	vector<long long >z;
	for(int i=1;i<=n;i++){
		z.push_back(abs(x-s[i]));
	}
	sort(z.begin(),z.end());
	long long i=0,cnt=0;
	for(i=0;i<n;i++){
	
		cnt+=z[i];
		if(cnt>m)break;
	}
	return i;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i];
	sort(s+1,s+1+n);
	for(int i=s[1];i<=s[n];i++)ans=max(ans,check(i));
	cout<<ans;
	return 0;
}