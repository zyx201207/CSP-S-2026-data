//crystal
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define emdl '\n'
typedef long long ll;
const int MAXN=5e5+5;

int n,m;
int a[MAXN];

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("cryatal.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+1+n,[](int &a,int &b){
		return a<b;
	});
	
	int d[MAXN];
	for(int i=1;i+1<=n;i++){
		d[i]=a[i+1]-a[i];
	}
	int sum[MAXN];
	for(int i=1;i<=n;i++){
		sum[i]=d[i]+sum[i-1];
	}
	
	int ans=-1;
	int cnt=0;
	int l=0;
	for(int r=1;r+1<=n;r++){
		cnt+=(r-l)*d[r];
		if(cnt<=m){
			ans=max(ans,r-l+1);
		}
		else{
			cnt=cnt-sum[r-1]+sum[l-1];
			l++;
		}
	}
	cout<<ans<<emdl;
	
	return 0;
}
