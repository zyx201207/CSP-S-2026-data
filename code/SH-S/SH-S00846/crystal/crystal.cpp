#include<bits/stdc++.h>
using namespace std;
int n,m;
int pre[500005];
int p[500005];
int a[500005];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		if(i!=1) pre[i]=pre[i-1]+a[i]-a[i-1];
		p[1]=a[1];
	for(int i=1;i<=n;i++)
		if(i!=1) p[i]=p[i-1]+a[i];	
	
	
	//for(int i=1;i<=n;i++) cout<<pre[i]<<" ";
	int ma=-1;
	for(int i=1;i<=n;i++){
		int l=1,r=i-1;
		while(l<=r){
			int mid=l+r>>1;
			if((i-mid)*a[i]-p[i-1]+p[mid-1]>m) l=mid+1;
			else r=mid-1;
		}
		r++;
		ma=max(ma,i-r+1);
	}
	cout<<ma;
	return 0;
}
