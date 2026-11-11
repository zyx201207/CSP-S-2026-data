#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005];
long long l,r,mid,l1;
void dfs(){
	mid=n;
	for(int f=0;f<n-1;f++){
		r=n-1;
		long long mini; 
		while(r>=mid-1){
		long long k=0,l=0;
		mini=1000000000001;
			for(long long i=r;r-i+1<=mid;i--){
				l+=b[i];
				k+=l;
			}
			r--;
			mini=min(mini,k);
		}
		if(mini>m){
			mid--;
		}
		else break;
	}
	return;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio,cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(long long i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(long long i=0;i<n-1;i++){
		b[i]=a[i+1]-a[i];
	}
	dfs();
	cout<<mid+1;
	return 0;
}
