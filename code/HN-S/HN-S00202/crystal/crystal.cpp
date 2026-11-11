#include<bits/stdc++.h>
using namespace std;
#define int long long
int b[100000005],a[10000005];
int ans=0;
int dc[100000005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	int maxn=0;
	sort(b+1,b+1+n);
	int mid=0;
	for(int i=1;i<=n;i++){
		mid+=b[i];
	}
	mid/=n;
	for(int i=1;i<=n;i++){
		a[i]=mid-b[i];
		if(a[i]>0){
			m-=mid-b[i];
			b[i]+=mid-b[i];
		}
	}
	for(int i=1;i<=n;i++)
	{
		a[b[i]]++;
		maxn=max(maxn,a[i]);
	}
	cout<<maxn;
	return 0;
}










