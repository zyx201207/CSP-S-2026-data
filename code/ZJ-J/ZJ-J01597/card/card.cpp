#include<bits/stdc++.h>
#define IOSO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl '\n'
#define QwQ return 0;
#define int long long
using namespace std;
const int N=5e5+10;
int mxr[N],cnt[N],tot[N];
int a[N];
signed main(){
	IOSO;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mxr[a[i]]=i;
	}
	a[n+1]=m+1;
	for(int i=1;i<=n;i++){
		int w=a[i];
		tot[mxr[w]]+=1;
		tot[mxr[w]]+=tot[i-1];
	}
	for(int i=1;i<=n;i++){
		cnt[a[i]]=max(cnt[a[i]],tot[i]);
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	cout<<endl;
	QwQ;
}