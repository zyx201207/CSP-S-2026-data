#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,a[N],pre[N],ans;
bool check(int x,int y){
	int sum=0;
	sum=a[y]*(y-x+1)-(pre[y]-pre[x-1]);
	return sum<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=i,mid,r=n,temp=0;
		while(l+1<r){
			mid=(l+r)/2;
			temp=mid;
			if(check(i,mid)){
				l=mid;
			}
			else{
				r=mid;
			}
		}
		if(check(i,r))temp=r;
		else if(check(i,(l+r)/2))temp=(l+r)/2;
		else if(check(i,l))temp=l;
		ans=max(temp-i+1,ans);
	}
	cout<<ans;
	return 0;
}
