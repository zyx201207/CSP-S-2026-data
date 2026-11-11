#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500050],b[500050];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,maxx=-1e9,ans;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n);
	b[0]=0;
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}for(int i=1;i<=n;i++){
		int l=1,r=i,mid=(i+1)/2-1;
		while(l!=r-1){
			if(i*a[i]-b[i]<=m){
				l=i;
				break;
			}
			if(mid*a[mid]-b[mid]<=m){
				l=mid;
				mid=(mid+r)/2+1;
			}if(mid*a[mid]-b[mid]>m){
				r=mid;
				mid=(l+mid)/2;		
			}
		}
		if(l>=maxx){
			maxx=l;
		}
	}
	cout<<maxx;
	return 0;
}
