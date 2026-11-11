#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int a[500100];
bool cmp(int a,int b){
	return a<b;
}
int ans=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int maxn=0;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	int l=1,r=0;
	int sum=0,k=0;
	for (int i=1;i<=n;i++){
		r=i;
		sum+=k*(a[r]-a[r-1]);
		while(sum>m){
			l++;
			sum=sum-(a[r]-a[l]);
		}
		k=r-l+1;
		ans=max(ans,k);
	}
	cout<<ans;
	return 0;
} 
