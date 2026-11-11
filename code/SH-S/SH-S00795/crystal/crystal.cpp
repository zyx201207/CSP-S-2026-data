#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int V=5e5+10;
int n;
int l=0;
int r=0;
int ans=1;
ll m;
ll a[V];
ll qzh[V];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	qzh[0]=a[0];
	for(int i=1;i<n;i++){
		qzh[i]=qzh[i-1]+a[i];
	}
	
	while(r<n){
		if( (r-l+1)*a[r]-(qzh[r]-qzh[l]+a[l]) <=m ){
			ans=max(ans,r-l+1);
			r++;
		}else{
			l++;
		}
	}

	cout<<ans;

	return 0;
}
