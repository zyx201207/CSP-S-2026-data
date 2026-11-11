#include<bits/stdc++.h>
#define ll long long
#define int long long
#define N 200050
#define M 1
#define rep(a,b,c) for(int a=(b);a<=(c);a++)
using namespace std;
ll n,m,a[N],ans;
vector<ll>vt[35];
bool v[N],if1[N][35];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<=30;j++){
			if(a[i]&(1<<j)){
				vt[j].push_back(i);
				if1[i][j]=1;
			}
		}
		v[i]=1;
	}
	for(int i=30;i>=0;i--){
		if(vt[i].size()<m)continue;
		ll num=0;
		for(int j=0;j<vt[i].size();j++){
			if(v[vt[i][j]])num++;
		}
		if(num<m)continue;
		ans+=(1<<i);
		for(int j=1;j<=n;j++){
			v[j]&=if1[j][i];
		}
	}
	cout<<ans<<endl;
	return 0;
} 
//Trick||Treat!
