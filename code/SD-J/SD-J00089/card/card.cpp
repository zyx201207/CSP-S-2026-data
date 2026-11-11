#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N],st[N];
int n,m;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	queue<int> q;
	cin>>n>>m;
	int k=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(st[a[i]]) k=i;
	}
	for(int i=1;i<=n;i++){
		int ans=0,flag=0;
		for(int j=1;j<=n;j++){
			for(int l=k;l<=n;l++)
				if(a[l]==i) flag=1;
			if(flag==1) ans++;
		}
		if(ans) cout<<ans<<" ";
	}
	return 0; 
}

