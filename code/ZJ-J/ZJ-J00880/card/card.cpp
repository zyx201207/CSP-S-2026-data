#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,M=3e5+3;
int n,m,a[N],cx[M],ans[M];
bool f=1;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i-1]>a[i])
			f=0;
	}
	if(f){
		for(int i=1;i<=n;i++)
			cx[a[i]]=i;
		for(int i=1;i<=m;i++)
			cout<<cx[i]<<' ';
		return 0;
	}
	for(int i=1;i<=n;i++){
		memset(cx,0,sizeof cx);
		for(int j=i;j<=n;j++){
			if(cx[a[j]]){
				for(int k=1;k<=m;k++)
					if(cx[k]<j&&cx[k]>cx[a[j]])
						cx[k]=0;
			}
			cx[a[j]]=j;
		}
		for(int i=1;i<=m;i++)
			if(cx[i])
				ans[i]++;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return 0;
}
