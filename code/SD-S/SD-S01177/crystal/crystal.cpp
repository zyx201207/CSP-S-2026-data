#include<bits/stdc++.h>
#define lowbit ((x)&(-x))
#define ls(u) ((u)<<1)
#define rs(u) (((u)<<1)|1)

using namespace std;
typedef long long ll;
typedef pair<int,int> PII;

const int N=5e5+5,INF=0x3f3f3f3f,mod=998244353;
const double eps=1e-9;

ll n,m,a[N],d[N],l=1,r=2,sum,cnt,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	sum=0,cnt=1,ans=0;
	for(r=2;r<=n;r++){
		sum+=cnt*(a[r]-a[r-1]),cnt++;
		while(sum>m)sum-=a[r]-a[l++],cnt--;
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
