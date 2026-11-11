#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int f[N],a[N];
bool vis[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int ans=0;
	f[1]=a[n];
	vis[n]=1;
	for(int i=2;i<=m;i++){
		int l=1,r=n,maxx,q=0;
		while(l<r&&r<=n){
			int mid=(l+r)/2;
			if(a[mid]>=f[i-1]){
				r=mid;	
			}else{
				l=mid+1;
			}
		}
		while(l<=n&&vis[l]){
			l++;
		}
		maxx=int(f[i-1]&a[l]);
		q=l;
		l=1,r=n;
		while(l<r&&l>=1){
			int mid=(l+r+1)/2;
			if(a[mid]<=f[i-1]){
				l=mid;
			}else{
				r=mid-1;
			}
		}
		while(l>=1&&vis[l]){
			l--;
		}
		if(maxx<int(f[i-1]&a[l])){
			vis[l]=1;
			f[i]=f[i-1]&a[l];
		}
		else{
			vis[q]=1;
			f[i]=maxx;
		}
	}
	cout<<f[m];
	return 0;
}

 
