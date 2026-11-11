#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],vis[N],ans;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		int mmx=-1;
		for(int j=1;j<=mid;j++){
			int mx=0;
			int an=0;
			for(int i=1;i<=n;i++){
				if(a[i]>a[mid])break;
				mx+=a[mid]-a[i];
				an++;
			}
			if(mx<=m)ans=max(an-j+1,ans);
			mmx=max(mmx,mx);
		}
		if(mmx>m)r=mid-1;
		else l=mid+1;
	}
	cout<<ans<<"\n";
	return 0;
}
/*
I must win!
*/
