#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e5+5;
int a[N],sum[N];
int s[N],tot=0;
int first_pos[N],end_pos[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
 	int n,m;
 	cin>>n>>m;
 	for(int i=1;i<=n;i++){
 		cin>>a[i];	
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		if(a[i]!=a[i-1])
		{
			s[++tot]=a[i];
			first_pos[tot]=i;
			end_pos[tot-1]=i-1;
		}
	}
	end_pos[tot]=n;
//	for(int i=1;i<=tot;i++){
//		cout<<first_pos[i]<<' '<<end_pos[i]<<'\n';
//	}
	int ans=0;
	for(int i=1;i<=tot;i++){
//		cout<<i<<"----\n";
		int res=end_pos[i]-first_pos[i]+1;
		int lo=0,hi=first_pos[i];
		int fp=first_pos[i];
		int lim=0;
		while(lo<=hi){
			int mid=(lo+hi)>>1;
//			cout<<mid<<" "<<mid*s[i]<<" "<<*(sum[fp-1]-sum[fp-mid-1])<<" ";
			if(mid*s[i]-(sum[fp-1]-sum[fp-mid-1])<=m){
//				cout<<1<<"\n";
				lim=mid;
				lo=mid+1;
			}
			else{
//				cout<<0<<"\n";
				hi=mid-1;
			}
		}
//		cout<<lim<<'\n';
		ans=max(ans,lim+res);
	}
	cout<<ans<<"\n";
} 
