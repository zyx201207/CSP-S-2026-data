#include <bits/stdc++.h>
#define int long long
const int N=5e5+100;
using namespace std;
typedef pair<int,int> pii;
int a[N];
int n,m;
int ans[N];
int hq(int x,int y){
	return ans[y]-((a[y]-a[x-1])*(x-1)+ans[x-1]);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int l,r;
	cin>>n>>m;
	int ff=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);
	} 
	sort(a+1,a+n+1);
	bool flag=0;
	ff=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=ff)flag=1;
	}
	if(flag==0){
		int tr=0;
		int cntt=1;
		for(int i=1;i<=n;i++){
			tr+=ff*i;
			cntt++;
			if(tr>m){
				cout<<cntt-1;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	ans[1]=0;
	for(int i=2;i<=n;i++){
		ans[i]=ans[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	int mmax=0;
	for(int i=1;i<n;i++){
		for(int j=i;j<=n;j++){
			if(hq(i,j)<=m)
				mmax=max(mmax,j-i+1);
		}
	}
	cout<<mmax;
	return 0;
}
//Oct31==Dec25?
/*
5 8
-3 -1 2 2 7
5 5
1 2 4 8 9
*/
