#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define faster ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int N=1e6+10,M=1e3+10,mod=1e9+7;
int n,m;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	faster;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int j=n;j>=1;j--){
		int mb=a[j],sum=0;
		for(int i=1;i<=n;i++){
			if(a[i]<mb){
				sum+=mb-a[i];
			}
		}
		if(sum<=m){
			cout<<j;
			return 0;
		}
	}	
	return 0;
}
