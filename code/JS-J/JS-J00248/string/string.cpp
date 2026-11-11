#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0;
	cin>>n;
	vector<int>a(n+1);
	vector<char>s(n+1);
	for(int i=1;i<=n;i++)cin>>a[i]>>s[i];
	for(int l=1,r=n;l<=r;){
		if(s[l]==s[r]){
			if(a[l]>=a[r]){a[l]-=a[r];r--;}
			else{a[r]-=a[l];l++;}
		}
		else{
			ans+=min(a[l],a[r]);
			if(a[l]>=a[r]){a[l]-=a[r];r--;}
			else{a[r]-=a[l];l++;}
		}
	}
	cout<<ans;
	return 0;
}
