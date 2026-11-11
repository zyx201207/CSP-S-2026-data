#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,i,l,r,mid,bao;
int a[510000],b[510000],c[510000];
bool check(int mid){
	int i,res=0;
	for(i=1;i<=mid;i++) res+=i*c[i];
	if(res<=m) return 1;
	for(i=mid+1;i<=n;i++){
		res=res-b[i]+b[i-mid]+c[i]*mid;
		if(res<=m) return 1;
	}
	return 0;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(i=1;i<=n-1;i++) c[i]=a[i+1]-a[i];
    for(i=1;i<=n-1;i++) b[i]=b[i-1]+c[i];
    l=1;
    r=n-1;
    while(l<=r){
    	mid=(l+r)/2;
		if(check(mid)){
			bao=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<bao+1;
}