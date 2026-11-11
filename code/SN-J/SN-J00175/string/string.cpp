#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0,minn=0,maxx=-1;
	string c[200005];
	int a[200005];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		maxx=max(maxx,a[i]);
	}
	minn=maxx;
	for(int i=1;i<=n;i++){
	    minn=maxx;
		if(c[i]!=c[n+1-i]){
			minn=min(a[i],a[n+1-i]);
			cnt+=minn;
		}
	}
	cout<<cnt;
	return 0;
}
