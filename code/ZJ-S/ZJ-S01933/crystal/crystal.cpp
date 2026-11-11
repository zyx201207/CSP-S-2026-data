#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
#define int long long
signed main(){
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	int n,m,res=0,tmp,t;
	cin>>n>>m;
	vector<int> a(n);
	for(auto &i:a)
		cin>>i;
	sort(a.begin(),a.end());
	for(int i=n-1;i;i--)
		a[i]-=a[i-1];
	a[0]=0;
	for(int i=1;i<n;i++){
		int lj=0;
		for(int j=1;i+j<n;j++){
			lj+=(j)*a[i+j-1];
			if(lj>m)
				break;
			res=max(res,j+1);
		}
	}
	cout<<res;
}