#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int a[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,mmax=-0x3f3f3f,sum=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			sum=a[i]&=a[i+j];
			mmax=max(sum,mmax);
		}
	}
	cout<<mmax;
	return 0;
}

