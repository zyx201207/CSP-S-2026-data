#include<bits/stdc++.h>
#define int long long
using namespace std;
const int LL_MAX=9223372036854775007ll;
vector<int>il;
int c,t,n,d;
bool check(int l,int r){
	int len=r-l+1;
	vector<int>min_v(len,LL_MAX),ways(len,0);
	min_v[0]=0;
	for(int i=l+1;i<=r;i++){
		for(int j=i-1;j>=l&&il[i]-il[j]<=d;j--){
			if(min_v[i-l]>min_v[j-l]+1){
				min_v[i-l]=min_v[j-l]+1;
				ways[i-l]=1;
			}else if(min_v[i-l]==min_v[j-l]+1){
				ways[i-l]++;
			}
		}
	}
	return ways[r-l]==2;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int ans=0;
		for(int i=0;i<n;i++){
			int x;cin>>x;
			il.push_back(x);
		}
		for(int i=0;i<n;i++){
			for(int j=i+2;j<n;j++){
				if(check(i,j))ans++;
			}
		}
		cout<<ans<<'\n';
		il.clear();
	}
	return 0;
}
