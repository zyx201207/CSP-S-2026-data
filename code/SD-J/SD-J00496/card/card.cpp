#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[1000010];
int t[3010];
int w[3010];
int ans[3010];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(t,0,sizeof(t));
		memset(w,0,sizeof(w));
		int l=1;
		t[l]=a[i];
		w[a[i]]=l;
		for(int j=i+1;j<=n;j++){
			if(w[a[j]]){
				l=w[a[j]];
			}else{
				t[++l]=a[j];
				w[a[j]]=l;
			}
		}
		for(int j=1;j<=l;j++){
			ans[t[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
