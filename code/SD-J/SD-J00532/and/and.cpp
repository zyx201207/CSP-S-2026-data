#include<bits/stdc++.h>
#define int long long
#define fi first
#define N 1001000
#define M 100100
#define P 998244353
#define PX 1000000007
#define se second
#define all(x) x.begin(),x.end()
#define fst ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define mod(x) (((x%P)+P)%P)
using namespace std;
int n,m,a[N][40],ans[40];
vector<int> ii;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	fst;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		int res=0;
		while(x){
			a[i][res++]=x%2;
			x/=2;
		}
		ii.push_back(i);
	}
	for(int j=30;j>=0;j--){
		vector<int> iii;
		for(int i:ii){
			if(a[i][j])iii.push_back(i);
		}		
		if((int)iii.size()>=m){
			ii.swap(iii);
			ans[j]=1;
		}
	}
	int aans=0;
	for(int i=30;i>=0;i--){
		aans*=2;
		aans+=ans[i];
	}
	cout<<aans;
	return 0;
}

