#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[500005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=n;i++){
		int x=a[i];
		vector<int> ve;
		for(int j=1;j<i;j++){
			ve.push_back(x-a[j]);
			cout<<x-a[j]<<" ";
		}
		cout<<endl;
		sort(ve.begin(),ve.end());
		int s=0,cnt=0;
		for(int t:ve){
			s+=t;
			if(s>m)break;
			cnt++;
		}
		ans=max(ans,cnt+1);
	}
	cout<<ans;
	
	
	
	return 0;
}
