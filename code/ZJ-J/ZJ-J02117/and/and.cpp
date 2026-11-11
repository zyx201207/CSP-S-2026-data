#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int a[N],cnt[40],n,m,maxl=0,l;
vector<int> dp[40];

int get(int n,int k){
	int i=0,tmp;
	while(n){
		i++;
		if(i==k) return n%2;
		n/=2;
	}
	return 0;
}

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int x;
	for(int i=1;i<=n;i++){
		x=a[i];
		l=0;
		while(x){
//			x/=2;
			cnt[++l]+=x%2;
			x/=2;
		}
		maxl=max(maxl,l);
	}
//	cout<<maxl<<' ';
//	for(int i=1;i<=maxl;i++) cout<<cnt[i]<<' ';
	while(cnt[maxl]<m&&maxl>0){
		maxl--;
	}
//	cout<<maxl;
	int t,li=maxl;
	for(int i=1;i<=n;i++){
		if(get(a[i],maxl))dp[li].push_back(a[i]);
	}
//	for(int i=0;i<=dp[li].size();i++) cout<<dp[li][i]<<' ';
	for(int i=maxl-1;i>0;i--){
		t=0;
		for(int j=0;j<dp[li].size();j++){
			if(get(dp[li][j],i)==1){
				dp[i].push_back(dp[li][j]);
				t++;
			}
		}
		if(t>=m) li=i;
//		for(int i=0;i<dp[li].size();i++) cout<<dp[li][i]<<' ';
//		cout<<endl;
	}
	int ans=dp[li][0];
	for(int i=1;i<m;i++){
		ans&=dp[li][i];
	}
	cout<<ans;
	return 0;
}

