#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans[N],vis[N],sum[N],ans2[N][2];
string s;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i-1]>a[i]) flag=1;
	}
	if(!flag){
		for(int i=1;i<=n;i++){
			vis[a[i]]++;
		}
		for(int i=1;i<=m;i++){
			sum[i]=sum[i-1]+vis[i];
		}
		for(int i=1;i<=n;i++) cout<<(vis[i]==0?0:sum[i])<<" ";
		return 0;
	}
	if(m==2){
		int cnt1=0,cnt2=0; 
		for(int i=1;i<=n;i++){
			if(a[i]==1) cnt1++;
			else cnt2++;
		}
		ans2[0][1]=cnt1;
		ans2[0][2]=cnt2;
		for(int i=1;i<=n;i++){
			ans2[i][1]=ans2[i-1][1];
			ans2[i][2]=ans2[i-1][2];
			ans2[i][a[i]]--;
		}
		int sum1=0,sum2=0;
		for(int i=1;i<=n;i++){
			if(ans2[i][1]!=0) sum1++;
			if(ans2[i][2]!=0) sum2++;
		}
		cout<<sum1<<" "<<sum2;
		return 0;
	}
	return 0;
}
