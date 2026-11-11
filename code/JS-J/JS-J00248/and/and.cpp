#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans=0;
	cin>>n>>m;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=0;i<(1<<(n+1));i++){
		int cnt=0,s;
		for(int j=1;j<=n;j++){
			if(i&(1<<j)){
				if(cnt==0)s=a[j];
				else s=(s&a[j]);
				cnt++;
			}
		}
		if(cnt==m)ans=max(ans,s);
	}
	cout<<ans;
	return 0;
}
