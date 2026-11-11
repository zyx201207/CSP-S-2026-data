#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(i) i<<1
#define rs(i) i<<1|1
#define lowbit(x) x&-x
const int N=2e5+10;
const int M=5e5+10;
const int base=1e9+7;
const int base1=1e9+9;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
int n,m;
int a[N];
bool vis[N];
bool vis1[N];
int ans;
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=31;i>0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(vis[j])	continue;
			if((a[j]>>(i-1))&1){
				cnt++;
			}else{
				vis1[j]=1;
			}
		}
		if(cnt>=m){
			ans=(ans<<1)|1;
			for(int j=1;j<=n;j++){
				if(vis1[j])	vis[j]=1;
			}
		}else{
			ans<<=1;
			for(int j=1;j<=n;j++){
				vis1[j]=0;
			}
		}
	}
	cout<<ans;
    return 0;
}
/*
4 2
3 15 12 12
*/
