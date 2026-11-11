#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500010];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=0,sum=0;
	queue<int>q;
	q.push(a[1]);
	for(int i=2;i<=n;i++){
		q.push(a[i]);
		sum+=(a[i]-a[i-1])*(q.size()-1);
		if(sum>m){
			while(sum>m){
				sum-=a[i]-q.front();
				q.pop();
			}
		}
//		cout<<i<<' '<<sum<<endl;
		ans=max(ans,(int)(q.size()));
	}
	
	cout<<ans;
}
