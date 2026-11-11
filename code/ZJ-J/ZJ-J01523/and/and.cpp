#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
int x[40];
bool cmp(int v,int u){
	return v>u;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=0;i<=30;i++){
		x[i]=(1<<i);
	}
	for(int i=30;i>=0;i--){
		int l=0,r=n+1;
		a[r]=0;
		while(l<=r){
			int mid=(l+r)/2;
			if(a[mid]<x[i])r=mid-1;
			else l=mid+1;
		}
		if(l>m){
			
			ans+=x[i];
			n=l-1;
			sort(a+1,a+n+1,cmp);
		}
		for(int j=1;j<l;j++){
			a[j]-=x[i];
		}
	}
	cout<<ans;
	return 0;
}