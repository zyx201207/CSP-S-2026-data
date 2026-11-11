#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,a[N],cnt[35],ans;
struct node{
	int val;
	int bit[35];
	bool operator<(const node&o)const{
		for(int i=1;i<=30;i++){
			if(cnt[i]>=m&&bit[i]!=o.bit[i]){
				return bit[i]>o.bit[i];
			}
		}
		return true;
	}
}s[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int t=a[i];
		s[i].val=a[i];
		for(int j=30;j>=1;j--){
			cnt[j]+=t&1;
			s[i].bit[j]=t&1;
			t>>=1;
		}
	}
	stable_sort(s+1,s+1+n);
	ans=s[1].val;
	for(int i=2;i<=m;i++){
		ans=(ans&s[i].val);
	}
	cout<<ans;
	return 0;
}