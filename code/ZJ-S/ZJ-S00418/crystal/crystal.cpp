#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=500005;

int n,m,a[N],p[N];

bool check(int i,int pos){
	int add=a[i]*(i-pos)-(p[i-1]-p[pos-1]);
	return add<=m;
} 

signed main() {
//	fc crystal.out crystal1.ans
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		p[i]=p[i-1]+a[i];
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		int l=1,r=i,mid,pos;
		while(l<=r){
			mid=l+r>>1;
			if(check(i,mid)){
				r=mid-1;
				pos=mid;
			}else {
				l=mid+1;
			}
		}
		
		ans=max(ans,i-pos+1);
	} 
	
	cout<<ans<<'\n';
	
	/*
	i=1~n,try to all be a[i],
	binary search smallest pos that : 
	a[i]*(i-pos)-sum(a[pos~i-1])<=m
	
	
	*/
	return 0;
}
