#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,num=0,maxn=0,nn=0;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		num+=a[i];
	}
	long long sum=(num+m)/n;
	for(long long i=1;i<=n;i++){
		if(a[i]<=sum);
			nn++;
			maxn++;
		if(a[i]>=sum+1){
			maxn--;
		}
	}
	if(nn==n) cout<<maxn;
	else cout<<maxn-2;
	return 0;
} 
