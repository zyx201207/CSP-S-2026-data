#include<bits/stdc++.h>
using namespace std;
long long n,sum=0;
const int N=2e5+10;
long long a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long l=1,r=n;
	while(l<r){
		long long mn=min(a[l],a[r]);
		a[l]-=mn;
		a[r]-=mn;
		if(c[l]!=c[r]) sum+=mn;
		if(a[r]==0) r--;
		if(a[l]==0) l++;
	}
	cout<<sum;
	return 0;
}
