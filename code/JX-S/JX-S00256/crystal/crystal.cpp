#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(i) i<<1
#define rs(i) i<<1|1
#define lowbit(x) x&-x
const int N=5e5+10;
const int M=5e5+10;
const int base=1e9+7;
const int base1=1e9+9;
int n,m;
int a[N];
int res=0;
int sum[N];
int ans=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
        cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
        int l=1,r=i;
        res=i;
        while(l<=r){
            int mid=(l+r)>>1;
            if(a[i]*(i-mid)-(sum[i-1]-sum[mid-1])<=m){
                r=mid-1;
                res=mid;
            }else{
                l=mid+1;
            }
        }
        ans=max(ans,i-res+1);
	}
	cout<<ans;
	return 0;
}
