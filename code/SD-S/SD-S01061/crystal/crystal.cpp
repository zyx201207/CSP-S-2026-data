#include<bits/stdc++.h>
#define int long long
using namespace std;
int z,q,n,m,a[500005],ju[500005],j[500005],mn=0,minn=0;
bool A=1,B=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1]){
			if(i==1)continue;
			B=0;
		}
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
			if(i==2)continue;
			A=0;
		}
	}
	if(B==1){
		cout<<n<<endl;
		return 0;
	}
	if(A==1){
		cout<<m/(a[2]-a[1])<<endl;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		mn=m;
		z=0;
		for(int j=i;j>=1;j--){
			if(mn>=a[i]-a[j]){
				mn=mn-a[i]+a[j];
				z++;
			}
		}
		minn=max(minn,z);
	}
	cout<<minn;
	return 0;
}
