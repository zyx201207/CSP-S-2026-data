#include <bits/stdc++.h>
using namespace std;
constexpr int MaxN = 5e5+5;
long long n,m,a[MaxN],def_a[MaxN],sum_def_a[MaxN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	cin>>a[0];
	for(auto i=1;i<n;i++){
		cin>>a[i];
		
	}
	sort(a,a+n);
	for(auto i=1;i<n;i++){
		def_a[i]=a[i]-a[i-1];
		sum_def_a[i]=def_a[i]+sum_def_a[i-1];
	}
	int ans=0;
	for(int i=n-2;i>=0;i--){
		int last=0;
		for(auto j=i-1;j>=0;j--){
			//if((sum_def_a[j]-sum_def_a[i])*(j-i)<=m) {ans = max(ans,j-i+1);continue;}
			last+=sum_def_a[i]-sum_def_a[j];
			if(last<=m) ans = max(ans,i-j+1); else break;
		}
	}
	cout<<ans<<endl;
	
	
	
	return 0;
}