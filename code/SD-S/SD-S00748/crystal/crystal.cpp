#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define int long long
using namespace std;
const int N=5e5+50;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int sum=0;
	int maxx=-1;
	int cnt=1;
	for(int i=n;i>=1;i--){
		cnt=1;
		sum=0;
		for(int j=i-1;j>=1;j--){
			//cout<<a[i]<<' '<<a[j]<<endl;
			sum+=a[i]-a[j];
			if(sum>m)break;
			cnt++;
		}
		//cout<<endl;
		maxx=max(cnt,maxx);
	}
	cout<<maxx;
	return 0;
}

