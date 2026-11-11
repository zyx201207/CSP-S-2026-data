#include<bits/stdc++.h>
#define PI pair<int,int>
#define ll long long

using namespace std;
const int N=5e5+10;
int n,m;
ll a[N],maxx=-1e18;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	
	for(int i=1;i<=n;++i){
		ll sum=0,l=1;
		for(int j=i-1;j>=1;--j){
			sum+=abs(a[i]-a[j]);
			if(sum>m){
				l=j+1;
				break;
			}
		} 
		maxx=max(maxx,i-l+1);
	}
	cout<<maxx<<"\n";
	return 0;
} 
