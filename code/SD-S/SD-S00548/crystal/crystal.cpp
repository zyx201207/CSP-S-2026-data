#include<bits/stdc++.h>
#define l(x) ((x)&-(x))
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define A first
#define B second
#define CT continue
#define rt return
#define umap unordered_map
#define pq priority_queue
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int N=5e5+10;
const int LOG=21;
int n,a[N],x,l,r,mid,res;
ll sum[N],m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
//	cout<<fixed<<setprecision(2);
	cin>>n>>m;
	for(int i=1;i<=n;i++){cin>>x;a[i]=x;}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i],l=1,r=n;
		while(l<r){
			mid=l+r>>1;
			if(a[i]*(i-mid+1)-
			(sum[i]-sum[mid-1])<=m) r=mid;
			else l=mid+1;
		}
		res=max(res,i-r+1);
	}
	cout<<res;
	return 0;
}

