#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e6+10;

int n,m;
int an[N];
int bn[N];
int maxn;

int check(int x){
	memset(bn,0,sizeof(bn));
	for(int i=1;i<=n;i++){
		if(an[i]>an[x]) break;
		bn[i]=an[x]-an[i];
	} 
	int sum=0;
	sort(bn+1,bn+1+n);
	for(int i=1;i<=n;i++){
		sum+=bn[i];
	}
	if(sum<=m) return 1;
	return 0;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>an[i];
	sort(an+1,an+1+n);
	int l=0,r=n,ans;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		} else {
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
} 
