#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e4+10;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[maxn];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	vector<int> b[maxn];
	for(int i=n-1;i>=1;i--){
		for(int j=i-1;j>=0;j--){
			b[i].push_back(a[i]-a[j]);
		}
	}
	int ans=-0x3f3f3f3f;
	for(int i=n-1;i>=1;i--){
		int f=0;
		int q=0;
		for(int j=0;j<b[i].size();j++){
			f+=b[i][j];
			if(f>m){
				break;
			}
			q++;
		}
		q+=1;
		ans=max(ans,q);
	}
	cout<<ans<<endl;
} 
