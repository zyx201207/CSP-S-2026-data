#include<bits/stdc++.h>
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define vp vector<pii>
using namespace std;
constexpr int N=2000000+10;
int c,T,n,d,a[N],q[N],hd,tl;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				vi nd; int now=i;
				nd.push_back(i);
				for(int k=i,l=i+1;k<=j;k=l+1){
//					cout<<now<<" "<<k<<endl;
					while(l+1<=j&&a[k]+d>=a[l+1]) l++;
					nd.push_back(l);
				}
				if(nd.back()!=j) nd.push_back(j);
//				cout<<i<<" "<<j<<endl;
//				for(int k:nd) cout<<k<<" ";cout<<endl;
				int cnt=0;
				for(int k=0;k<(int)nd.size()-2;k++){
//					cout<<k<<" "<<(int)nd.size()-2<<endl;
					for(int l=nd[k]+1;l<nd[k+1];l++){
//						cout<<l<<endl;
						if(a[l]+d>=a[nd[k+2]]) cnt++;
					}
				}
				if(cnt==1) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
