#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int r=n,l=n;
	long long res=m;
	int ans=1;
	while(r>=1){
		while(l-1>=1&&res>=a[r]-a[l-1]){
			res-=a[r]-a[l-1];
			l--;
		}
		ans=max(ans,r-l+1);
		if(r>1){
			res+=(a[r]-a[r-1])*(long long)(r-l+1);
		}
		r--;
	}
	cout<<ans<<endl;
	return 0;
}

