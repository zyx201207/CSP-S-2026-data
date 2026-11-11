#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],maxn;
int tjx(int x,int y){
	int sum=0;
	for(int i=x;i<y;i++) sum+=a[y]-a[i];
	return sum;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=1,x=0,y=0;
	while(l<=r && r<=n){
		while(tjx(l,r)<=m && r<=n){
			r++;
			if(y-x<r-l) y=r,x=l;
		}
		while(tjx(l,r)>m && l<=r) l++;
	}
	cout<<y-x;
	return 0;
} 
