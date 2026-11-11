#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N];
int D[N],cnt[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int res=0,ans=1,_m=m,l=1;bool flag=0;
	for(int i=2;i<=n;i++){
		D[i]=a[i]-a[i-1];
		if(a[i]==a[i-1]) cnt[i]=0;
		else cnt[i]=i-l;
		int z=D[i]*cnt[i];
		if(z>_m){
			int _l=1;
			while(z>_m){
				_m+=D[l+_l]*cnt[l+_l];
				_l++;
			}
			res=max(res,ans);
			ans=ans-_l+1;l+=_l;
		} else{
			ans++;_m-=z;
		}
	}
	cout<<max(res,ans);
	return 0;
}