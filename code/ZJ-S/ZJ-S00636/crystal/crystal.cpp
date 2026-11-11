#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl '\n'
#define int long long
using namespace std;
const int N=5e5+5;
int a[N];
int pre[N];
int n,m;
bool check(int x){
    for(int i=x;i<=n;i++){
        if(a[i]*x-(pre[i]-pre[i-x])<=m)return 1;
    }
    return 0;
}
signed main(void){
	IOS;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
    int l=0,r=n,ans=0;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)){
            l=mid+1;
            ans=mid;
        }else{
            r=mid-1;
        }
    }
    cout<<ans<<endl;
	return 0;
}
