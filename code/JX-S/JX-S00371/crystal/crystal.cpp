#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=n;
	while(l<=r){
		sum=0;
		int mid=(l+r)/2;
		for(int i=1;i<mid;i++){
			sum+=a[mid]-a[i];
		}
		if(sum<=m)l=mid+1;
		else r=mid-1;
		//cout<<r<<endl;
		//cout<<sum<<' '<<m<<' '<<a[313324]<<endl;
	}
	
	while(a[r+1]==a[r]){r++;}
	cout<<r;
	return 0;
}
