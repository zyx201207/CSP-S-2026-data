#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define first fi
#define second se
const int N=5e5+10;
const int mod=998244353;
int n,m,a[N],b[N],ans,l;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	l=1;
	for(int i=1;i<=n;i++){
		//cout<<(i-l+1)*a[i]-(b[i]-b[l-1])<<" ";
		while((i-l+1)*a[i]-(b[i]-b[l-1])>m){
			l++;
			//cout<<"i-"<<i<<"  l-"<<l<<"\n";
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
} 