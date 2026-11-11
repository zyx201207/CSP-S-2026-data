#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+10;
int n,m,b[N],a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==1){
		cout<<1<<endl;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=n-1;i>=1;i--)b[i]=a[n]-a[i];
	int i=1,j=1,k=0,l=-1;
	while(i<=n&&j<=n){
		l=max(l,j-i+1);
		j++;
		if(j>n) break;
		int x=(b[j-1]-b[j]);
		int y=x*(j-i);
		int lk=m-k-y;
		while(lk<0){
			k=k-(b[i]-b[j]);
			i++;
			lk=m-k-y;
		}
		k+=y;
	}
	cout<<l<<endl;
	return 0;     
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
	                      