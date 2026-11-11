#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
int cha[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,minn=0x7fffffff,maxn=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		minn=min(minn,a[i]);
		maxn=max(maxn,a[i]);
	}
	sort(a+1,a+n+1);
	cha[1]=0;
	for(int i=2;i<=n;i++){
		cha[i]=(a[i]-a[i-1])*(i-1)+cha[i-1];
	}
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)/2,sigma=0,minnn=0x7fffffff;
		for(int i=1;i<=n-mid+1;i++){
			minnn=min(minnn,cha[i+mid-1]-(i-1)*(a[i+mid-1]-a[i])-cha[i]);
		}
		
		if(minnn>m) r=mid;
		else l=mid+1;
		//cout<<l<<" "<<r<<" "<<mid<<" "<<minnn<<endl;
	}
	cout<<l-1; 
	return 0;
}
