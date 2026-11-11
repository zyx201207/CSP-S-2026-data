#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N];
int n,m;
bool isblue(int mid){
	if(mid==1) return true;
	int sum=0;
	
	for(int i=1;i<=mid;i++){
		sum+=a[mid]-a[i];
	}
	if(sum<=m) return true;
	for(int i=mid+1;i<=n;i++){
		sum-=a[i-1]-a[i-mid];
		sum+=(mid-1)*(a[i]-a[i-1]);
		if(sum<=m) return true;
	} 
	return false;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    int l=0,r=n+1;
    while(l+1<r){
    	int mid=(l+r)/2;
    	if(isblue(mid)) l=mid;
    	else r=mid;
	}
	cout<<l<<endl;
    return 0;
}

