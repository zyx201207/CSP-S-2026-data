#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[510000],cha[510000],pre[510000];
int n,m;
bool check(int l,int r){
	if(a[r]*(r-l)-pre[r-1]+pre[l-1]>m){
//		cout<<(r-l)<<endl;
//		cout<<a[r]*(r-l)-pre[r-1]+pre[l-1]<<endl;
//		cout<<l<<' '<<r<<endl;
		return 1;
	}
	else return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	pre[0]=0;
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
		//cout<<pre[i]<<endl;
	}
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)/2;
		//cout<<mid<<endl;
		if(check(mid,r))r=mid+1;
		else l=mid+1;
		//cout<<l<<' '<<r<<endl;
	}
	cout<<l;
	return 0;
}
/*5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/

