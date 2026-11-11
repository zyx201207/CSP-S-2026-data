#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m;
int a[N];
int qzh[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		qzh[i]=qzh[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int now=a[i];
		int l=1;
		int r=i-1;
		while(l<=r){
			int mid=(l+r)>>1;
			int sum=qzh[i]-qzh[mid-1];
			if(now*(i-mid+1)-sum<=m){
				ans=max(ans,i-mid+1);
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
人话：你能将这些值最多增加m
问你最多能得到多少个相同的数
*/
/*
5 5
1 2 4 8 9
*/
/*
文明与道德被埋葬在黎明前，踽行于无止境的风雪之中，伊塔库亚早已忘了自己为谁守夜
*/