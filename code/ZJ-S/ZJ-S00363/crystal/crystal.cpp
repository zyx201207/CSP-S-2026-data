#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005;
int n,m,a[N],d[N],sumd[N],ans;
signed main(){
//	system("fc crystal3.out crystal3.ans");
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		d[i]=a[i]-a[i-1];
		sumd[i]=sumd[i-1]+d[i];
	}
	int l=1,sum=0;
	for(int r=1;r<=n;r++){
		while(sum+d[r]*(r-l)>m){
			sum=sum-(sumd[r-1]-sumd[l]);
			l++;
		}
		sum=sum+d[r]*(r-l);
		ans=max(ans,r-l+1);
	}
	cout<<ans<<"\n";
}
