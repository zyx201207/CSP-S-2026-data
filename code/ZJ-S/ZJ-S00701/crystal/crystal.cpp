#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],b[500005];
int use(int x,int y){
	int h=b[y]-b[x-1];
	h-=(a[n]-a[y])*(y-x+1);
	return h;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[n]-a[i];
		b[i]+=b[i-1];
	}
	int h=0,l=0,r=0,maxn=1;
	for(int i=1;i<=n;i++){
		l++;
		while(1){
			int pp=use(l,r+1);
			if(pp<=m&&r+1<=n){
				r++;
			}
			else{
				break;
			}
		}
		maxn=max(maxn,r-l+1);
	}
	cout<<maxn<<"\n";
	return 0;
}
