#include<bits/stdc++.h>
using namespace std;
int n,m;
bool a[200010][40];
int pw[40];
int cnt[200010];
bool g[200010];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m;
	pw[0]=1;
	for(int i=1;i<=30;i++)
		pw[i]=pw[i-1]*2;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=30;j>=0;j--)
			if(x>=pw[j])
				x-=pw[j],a[i][j]=true;
	}
	for(int i=1;i<=n;i++)
		for(int j=30;j>=0;j--)
			if(a[i][j])
				cnt[j]++;
	for(int i=1;i<=n;i++)
		g[i]=true;
	int ans=0;
	for(int j=30;j>=0;j--)
		if(cnt[j]>=m){
			int sum=0;
			for(int i=1;i<=n;i++)
				if(g[i]&&a[i][j])
					sum++;
			if(sum>=m){
				ans+=pw[j];
				for(int i=1;i<=n;i++)
					g[i]&=a[i][j];
			}
		}
	cout<<ans;
	return 0;
}
