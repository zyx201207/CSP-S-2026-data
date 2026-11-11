#include<bits/stdc++.h>
#define umap unordered_map
#define mset multiset
#define fi first
#define se second
#define pb push_back
#define mkp make_pair
#define yes cout<<"Yes\n"
#define no cout<<"No\n"
#define all(x) (x).begin(),(x).end()
#define tmax(a,b) (a)=max((a),(b))
#define tmin(a,b) (a)=min((a),(b))
#define cout(x) cout<<fixed<<setprecision(x)
#define int LL

using namespace std;
typedef long long LL;typedef pair<int,int> PII;
typedef vector<int> vi;typedef vector<PII> vp;
typedef array<int,3> a3;typedef vector<a3> va3;

const int N=5e5+5;
int n,m,a[N],ans,sum[N];

bool check(int l,int r){
	int val=sum[r]-sum[l-1];
	return a[r]*(r-l+1)-val<=m;
}

signed main(){
//	system("fc crystal4.ans crystal.out");
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i,mid,res=i;
		while(l<=r){
			mid=l+r>>1;
			if(check(mid,i)){
				res=mid,r=mid-1;
			}else{
				l=mid+1;
			}
		}
		tmax(ans,i-res+1);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7

14:45
*/

