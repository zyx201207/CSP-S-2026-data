#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+10;
int N,M;
int ans;
int a[MAXN],pre[MAXN];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	// freopen("crystal4.in","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>N>>M;
	for(int i=1;i<=N;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+N);
	for(int i=1;i<=N;++i){
		pre[i]=pre[i-1]+a[i];
	}
	for(int i=1;i<=N;++i){
		int l=i,r=N;
		while(l<r){
			int mid=(l+r+1)>>1;
			int len=mid-i+1;
			if(a[mid]*len-(pre[mid]-pre[i-1])<=M){
				l=mid;
			}
			else{
				r=mid-1;
			}
		}
		ans=max(ans,l-i+1);
	}
	cout<<ans<<'\n';
	return 0;
}