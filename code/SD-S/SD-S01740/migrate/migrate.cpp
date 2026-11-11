#include<bits/stdc++.h>
using namespace std;
int c,t;
int n;
long long d;
long long x[2000006];
int b[2000006];
long long cnt,minn;
long long v;
long long ans=0;
void dfs(int k,int l)
{
	if(k>minn)	return ;
	if(x[l]==v){
		if(k==minn)
			cnt++;
		else{
			cnt=1;
			minn=k;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(abs(x[i]-x[l])>d||b[i])	continue;
		b[i]=1;
		dfs(k+1,i);
		b[i]=0;
	}
	return ;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++)	cin>>x[i];
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				minn=1e17;
				cnt=0;
				v=x[j];
				dfs(0,i);
				if(cnt==2)
					ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
