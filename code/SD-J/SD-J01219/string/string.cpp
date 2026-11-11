#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,a[N],l,r,sum;
char b[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	l=1,r=n;
	while(l<r){
		long long minn=min(a[l],a[r]);
		if(b[l]!=b[r]) sum+=minn;
		a[l]-=minn,a[r]-=minn;
		if(a[l]==0) l++;
		if(a[r]==0) r--;
	}
	cout<<sum;
	return 0;
} 
