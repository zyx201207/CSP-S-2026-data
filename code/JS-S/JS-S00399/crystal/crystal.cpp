#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>a(n+1,0),d(n,0);
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a.begin()+1,a.end());
	if(n<=5000){
		int ans=0;
		vector<vector<int>>d(n+1,vector<int>(n+1,0));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				d[i][j]=abs(a[i]-a[j]);
			}
		}
		for(int i=1;i<=n;i++){
			sort(d[i].begin()+1,d[i].end());
			int cnt=0,s=0;
			for(int j=1;j<=n;j++){
				cnt+=d[i][j];
				if(cnt>m)break;
				s++;
			}
			ans=max(ans,s);
		}
		cout<<ans;
	}
	else{
		int c=m/(a[2]-a[1]);
		for(int i=n-1;i>=1;i--){
			int s=i*i/2;
			if(s<=c){
				cout<<i+1;
				return 0;
			}
		}
	}
	return 0;
}
