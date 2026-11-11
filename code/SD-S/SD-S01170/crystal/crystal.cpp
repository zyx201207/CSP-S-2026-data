#include<bits/stdc++.h>
#define int long long
const int N=5e5+10;
using namespace std;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	
	int ans1=-1e12-10,maxi=0;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int cha=0;
		for(int j=i;j>=1;j--){
			cha+=abs(a[i]-a[j]);
		}
		if(cha<=m){
	
			maxi=i;
		}
		
	}
	cout<<maxi;
	
	return 0;
}
