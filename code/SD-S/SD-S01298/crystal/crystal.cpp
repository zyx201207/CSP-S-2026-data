#include<iostream>
#include<cstdio>
#include<algorithm>
#define LL long long
using namespace std;
int n;
LL m;
const int N=5e5+5;
LL a[N];
int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=1,r=1;
	long long sum=0,ans=0;
	while(l<=r&&r<=n){
		while(r<=n&&sum<=m){
			r++;
			sum+=(a[r]-a[r-1])*(r-l);
		} 
		ans=max(ans,(long long)r-l);
//		cout<<pr[i]<<endl;
		while(sum>m){
			sum-=(a[r]-a[l]);
			l++;
		}
	}
	cout<<ans;
	return 0;
}
