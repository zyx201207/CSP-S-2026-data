#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=5e5+10;

int arr[N],dis[N],mus[N],n,m;

bool cmp(int x,int y){
	return x>y;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+1+n,cmp);
	dis[1]=mus[1]=0;
	for(int i=2;i<=n;i++){
		dis[i]=arr[i-1]-arr[i];
		mus[i]=(n-i+1)*dis[i];
		mus[i]+=mus[i-1];
	}
	for(int i=1;i<=n;i++){
		dis[i]+=dis[i-1];
	}
	int ans=0;
	for(int i=2;i<=n;i++){
		int l=i,r=n;
		while(l<r){
			int mid=(l+r+1)>>1;
			int w=(mus[mid]-mus[i-1])-(n-mid)*(dis[mid]-dis[i-1]);
			if(w>m){
				r=mid-1;
			}else{
				l=mid;
			}
		}
		if(l==i && dis[l]>m)l--;
		ans=max(ans,l-i+2);
	}
	cout<<ans<<endl;
	
	return 0;
}

