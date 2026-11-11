#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m;
int c[N],s[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+c[i];
	}
	int mx=1;
	for(int i=1;i<=n;i++){
		int l=1,r=i,ans=-1;
		while(l<=r){
			int mid=(l+r+1)/2;
			if(1ll*(i-mid+1)*c[i]-1ll*(s[i]-s[mid-1])<=m){
//				cout<<i-mid+1<<"\n";
				r=mid-1;
				ans=mid;
			}
			else{
				l=mid+1;
			}
		}
		mx=max(mx,i-ans+1);
	}
	cout<<mx;
	return 0;
}
/*
5 5
1 2 4 8 9
*/

//Oct31==Dec25?
