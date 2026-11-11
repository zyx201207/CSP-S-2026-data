#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int maxv=-1;
	int ans=0x7fffffff;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxv=max(maxv,a[i]);
		ans&=a[i];
	}
	if(m==1)cout<<maxv<<endl;
	else if(m==n)cout<<ans<<endl;
	else{
		int maxa=0;
		for(int mask=1;mask<(1<<n);mask++){
			if(__builtin_popcount(mask)!=m)continue;
			int cur=0x7fffffff;
			for(int j=1;j<=n;j++){
				if(mask&(1<<(j-1)))cur&=a[j];
			}
			maxa=max(maxa,cur);
		}
		cout<<maxa<<endl;
	}
}
